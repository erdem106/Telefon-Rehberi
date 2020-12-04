#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <locale.h>
#include <vector>

using namespace std;
void anamenu();
void numaraEkle();
void kayýtGöster();
void IDArama();
void IDkayýtSil();
void isimkayýtSil();
void kayýtDüzenle();
void isimArama();
void telArama();

class telefonRehberi
{
	int ID;
	char isim[30];
	char cepNo[15];
	char iþNo[15];

public:
	int getID() { return ID; }
	char* getisim() { return isim; }
	char* gettelefon() { return cepNo; }
	

	void storeData()
	{
		telefonRehberi k;
		cout << "\n----------Yeni Bir Numara Oluþturunuz-----------\n";
		cout << "Lütfen ID'nizi Giriniz:\n"; cin >> ID; cin.ignore();
		if (ID >= 0) 
		{
		cout << "Lütfen Ýsminizi ve Soyismnizi Giriniz:\n"; cin.getline(isim, 30);
		cout << "Lütfen Cep Telefonu Numaranýzý Giriniz:\n"; cin.getline(cepNo, 15);
		cout << "Lütfen Ýþ Numaranýzý Giriniz:\n"; cin.getline(iþNo, 15);
		cout << endl;
		}
		else 
		{
			cout << "Seri Numaranýz 0'dan Küçük Olamaz! \n";
			anamenu();
		}
		
	}

	void showData()
	{
		cout << "\n----------Telefon Rehberiniz----------\n";
		cout << "ID'niz:   " << ID << endl;
		cout << "Ýsim Ve Soyisminiz:   " << isim << endl;
		cout << "Cep Telefonu Numaranýz:   " << cepNo << endl;
		cout << "Ýþ Numaranýz:   " << iþNo << endl;
	}

}; telefonRehberi b;

void numaraEkle()
{
	ofstream file;
	
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	
	b.storeData();
	file.write((char*)&b, sizeof(b));
	file.close();
	
	cout << "\nKayýt,Dosyaya kaydedildi.\n";
}

void kayýtGöster()
{

	ifstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	while (file.read((char*)&b, sizeof(b)))
	{
		b.showData();
	}

	file.close();
	cout << "Dosyadan Okuma Tamamlandý.\n";
}

void IDArama()
{

	ifstream file;
	int i;
	int x = 0;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	cout << "Aradýðýnýz ID numarasýný giriniz:\n";
	cin >> i;

	while (file.read((char*)&b, sizeof(b)))
	{
		if (i == b.getID())
		{
			b.showData();
			x++;
			cout << "ID Numarasý Bulundu: \n" << i;
		}

	}
	file.close();
	if (x == 0)
	{
		cout << "Aradýðýnýz ID Numarasý: " << i << " Kayýtlarda Yok.";
	}

	cout << "Dosyadan Veri Okuma Tamamlandý.\n";

}
void isimArama()
{
	char is[20];
	fstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app | ios::ate | ios::in);
	cout << "Aradýðýnýz Adý Giriniz:";
	cin >> is;
	file.seekg(0, ios::beg);
	int found = 0;
	while (file.read((char*)&b, sizeof(b)))
	{
		if (strcmp(is, b.getisim()) == 0)
		{
			found++;
			b.showData();
		}
	}
	file.close();
	if (found == 0) {
		cout << "-----Kayýt Bulunamadý-----\n";

	}
	cout << "Dosya Okuma Tamamlandý\n";

}
void telArama()
{

	char telno[15];
	fstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app | ios::ate | ios::in);

	cout << "Aradýðýnýz Telefon Numarasýný Giriniz:";
	cin >> telno;
	file.seekg(0, ios::beg);
	int found = 0;
	while (file.read((char*)&b, sizeof(b)))
	{
		if (strcmp(telno, b.gettelefon()) == 0)
		{
			found++;
			b.showData();
		}
	}
	file.close();
	if (found == 0) {
		cout << "-----Kayýt Bulunamadý-----";
	}
	cout << "Dosya Okuma Tamamlandý\n";
}
void isimkayýtSil()
{
	fstream file;
	ofstream file2;

	char k[100];

	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary | ios::app);
	file2.open("Geçici.txt", ios::out | ios::binary);
	cout << "Silinmesini Ýstediðiniz Kiþinin Ýsmini Giriniz: \n";
	cin >> k;

	file.seekg(0, ios::beg);
	int found = 0;
	file.read((char*)&b, sizeof(b));
	while (!file.eof())
	{
		if (strcmp(k, b.getisim()) != 0)
		{
			file2.write((char*)&b, sizeof(b));

		}
		else
		{
			cout << "Kaydýnýz Siliniyor:\n";
			found++;
		}
		file.read((char*)&b, sizeof(b));
	}
	if (found == 0)
	{
		cout << "----Kayýt Bulunamadý----\n";
	}

	file2.close();
	file.close();
	remove("TelefonRehberi.txt");
	rename("Geçici.txt", "TelefonRehberi.txt");


	cout << "Dosya Okuma Tamamlandý \n";
}
void IDkayýtSil()
{
	fstream file;
	ofstream file2;

	int k;

	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary | ios::app);
	file2.open("Geçici.txt", ios::out | ios::binary);
	cout << "Silinmesini Ýstediðiniz Kiþinin ID'sini Giriniz: \n";
	cin >> k;

	file.seekg(0, ios::beg);
	int found = 0;

	while (file.read((char*)&b, sizeof(b)))
	{
		if (k != b.getID())
		{
			file2.write((char*)&b, sizeof(b));

		}

		else
		{
			cout << "Kaydýnýz Siliniyor:\n";
			found++;
		}

	}
	file2.close();
	file.close();
	if (found == 0)
	{
		cout << "----Kayýt Bulunamadý----\n";
	}
	remove("TelefonRehberi.txt");
	rename("Geçici.txt", "TelefonRehberi.txt");

    cout << "Dosya Okuma Tamamlandý \n";
}

void kayýtDüzenle()
{
	int k;
	fstream file;
	int pos;
	int found = 0;
    
	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary);
    cout << "Deðiþtirmek Ýstediðiniz Kiþinin Seri Numarasýný Giriniz: \n";
	
	cin >> k;

	while (file.read((char*)&b, sizeof(b))) 
	{
		pos = file.tellg();
		if (k == b.getID()) 
		{
			cout << "Alttaki Kayýt Deðiþtirilecektir! \n";
			b.showData();
			
			b.storeData();
			file.seekg(pos - sizeof(b));
			file.write((char*)&b, sizeof(b));
			cout << "Kaydýnýz Baþarýlý Bir Þekilde Deðiþtirilmiþtir! \n";
			break;
		}
		
    }
	file.close();
	if (found == 0) 
	{
     cout << "----Kayýt Bulunamadý-----\n";
     cout << "Dosya Okuma Tamamlandý \n";
	}

}
void anamenu() {

	int durum;

	do
	{
		cout << "............................................\n";
		cout << "           Telefon Rehberi Yöneticisi\n";
		cout << "............................................\n\n";
		cout << "::::::::::::::: Program Menüsü :::::::::::::::\n";
		cout << "0. Exit \n";
		cout << "1. Yeni Bir Numara Ekleme \n";
		cout << "2. Kayýttaki Bütün Numaralarý Göster \n";
		cout << "3. ID'ye Göre Arama \n";
		cout << "4. Ýsime Göre Arama \n";
		cout << "5. Telefon Numarasýna Göre Arama \n";
		cout << "6. Ýstenilen Bir Kayýdý Deðiþtirme \n";
		cout << "7. Ýstenilen Bir Kayýdý ID'ye Göre Silme \n";
		cout << "8. Ýstenilen Bir Kayýdý Ýsime Göre Silme \n";
		cout << "Yapmak istediðiniz Talimatý Giriniz: \n";
		cin >> durum;

		switch (durum)
		{

		case 1:  numaraEkle(); break;
		case 2:	 kayýtGöster(); break;
		case 3:	 IDArama(); break;
		case 4:  isimArama(); break;
		case 5:	 telArama(); break;
		case 6:	 kayýtDüzenle(); break;
		case 7:  IDkayýtSil(); break;
		case 8:  isimkayýtSil(); break;
		}
	} while (durum);

}

void main() 
{
    setlocale(LC_ALL, "Turkish");
	anamenu();
}