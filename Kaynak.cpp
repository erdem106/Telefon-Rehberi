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
void kay�tG�ster();
void IDArama();
void IDkay�tSil();
void isimkay�tSil();
void kay�tD�zenle();
void isimArama();
void telArama();

class telefonRehberi
{
	int ID;
	char isim[30];
	char cepNo[15];
	char i�No[15];

public:
	int getID() { return ID; }
	char* getisim() { return isim; }
	char* gettelefon() { return cepNo; }
	

	void storeData()
	{
		telefonRehberi k;
		cout << "\n----------Yeni Bir Numara Olu�turunuz-----------\n";
		cout << "L�tfen ID'nizi Giriniz:\n"; cin >> ID; cin.ignore();
		if (ID >= 0) 
		{
		cout << "L�tfen �sminizi ve Soyismnizi Giriniz:\n"; cin.getline(isim, 30);
		cout << "L�tfen Cep Telefonu Numaran�z� Giriniz:\n"; cin.getline(cepNo, 15);
		cout << "L�tfen �� Numaran�z� Giriniz:\n"; cin.getline(i�No, 15);
		cout << endl;
		}
		else 
		{
			cout << "Seri Numaran�z 0'dan K���k Olamaz! \n";
			anamenu();
		}
		
	}

	void showData()
	{
		cout << "\n----------Telefon Rehberiniz----------\n";
		cout << "ID'niz:   " << ID << endl;
		cout << "�sim Ve Soyisminiz:   " << isim << endl;
		cout << "Cep Telefonu Numaran�z:   " << cepNo << endl;
		cout << "�� Numaran�z:   " << i�No << endl;
	}

}; telefonRehberi b;

void numaraEkle()
{
	ofstream file;
	
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	
	b.storeData();
	file.write((char*)&b, sizeof(b));
	file.close();
	
	cout << "\nKay�t,Dosyaya kaydedildi.\n";
}

void kay�tG�ster()
{

	ifstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	while (file.read((char*)&b, sizeof(b)))
	{
		b.showData();
	}

	file.close();
	cout << "Dosyadan Okuma Tamamland�.\n";
}

void IDArama()
{

	ifstream file;
	int i;
	int x = 0;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app);
	cout << "Arad���n�z ID numaras�n� giriniz:\n";
	cin >> i;

	while (file.read((char*)&b, sizeof(b)))
	{
		if (i == b.getID())
		{
			b.showData();
			x++;
			cout << "ID Numaras� Bulundu: \n" << i;
		}

	}
	file.close();
	if (x == 0)
	{
		cout << "Arad���n�z ID Numaras�: " << i << " Kay�tlarda Yok.";
	}

	cout << "Dosyadan Veri Okuma Tamamland�.\n";

}
void isimArama()
{
	char is[20];
	fstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app | ios::ate | ios::in);
	cout << "Arad���n�z Ad� Giriniz:";
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
		cout << "-----Kay�t Bulunamad�-----\n";

	}
	cout << "Dosya Okuma Tamamland�\n";

}
void telArama()
{

	char telno[15];
	fstream file;
	file.open("TelefonRehberi.txt", ios::out | ios::binary | ios::app | ios::ate | ios::in);

	cout << "Arad���n�z Telefon Numaras�n� Giriniz:";
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
		cout << "-----Kay�t Bulunamad�-----";
	}
	cout << "Dosya Okuma Tamamland�\n";
}
void isimkay�tSil()
{
	fstream file;
	ofstream file2;

	char k[100];

	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary | ios::app);
	file2.open("Ge�ici.txt", ios::out | ios::binary);
	cout << "Silinmesini �stedi�iniz Ki�inin �smini Giriniz: \n";
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
			cout << "Kayd�n�z Siliniyor:\n";
			found++;
		}
		file.read((char*)&b, sizeof(b));
	}
	if (found == 0)
	{
		cout << "----Kay�t Bulunamad�----\n";
	}

	file2.close();
	file.close();
	remove("TelefonRehberi.txt");
	rename("Ge�ici.txt", "TelefonRehberi.txt");


	cout << "Dosya Okuma Tamamland� \n";
}
void IDkay�tSil()
{
	fstream file;
	ofstream file2;

	int k;

	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary | ios::app);
	file2.open("Ge�ici.txt", ios::out | ios::binary);
	cout << "Silinmesini �stedi�iniz Ki�inin ID'sini Giriniz: \n";
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
			cout << "Kayd�n�z Siliniyor:\n";
			found++;
		}

	}
	file2.close();
	file.close();
	if (found == 0)
	{
		cout << "----Kay�t Bulunamad�----\n";
	}
	remove("TelefonRehberi.txt");
	rename("Ge�ici.txt", "TelefonRehberi.txt");

    cout << "Dosya Okuma Tamamland� \n";
}

void kay�tD�zenle()
{
	int k;
	fstream file;
	int pos;
	int found = 0;
    
	file.open("TelefonRehberi.txt", ios::in | ios::out | ios::binary);
    cout << "De�i�tirmek �stedi�iniz Ki�inin Seri Numaras�n� Giriniz: \n";
	
	cin >> k;

	while (file.read((char*)&b, sizeof(b))) 
	{
		pos = file.tellg();
		if (k == b.getID()) 
		{
			cout << "Alttaki Kay�t De�i�tirilecektir! \n";
			b.showData();
			
			b.storeData();
			file.seekg(pos - sizeof(b));
			file.write((char*)&b, sizeof(b));
			cout << "Kayd�n�z Ba�ar�l� Bir �ekilde De�i�tirilmi�tir! \n";
			break;
		}
		
    }
	file.close();
	if (found == 0) 
	{
     cout << "----Kay�t Bulunamad�-----\n";
     cout << "Dosya Okuma Tamamland� \n";
	}

}
void anamenu() {

	int durum;

	do
	{
		cout << "............................................\n";
		cout << "           Telefon Rehberi Y�neticisi\n";
		cout << "............................................\n\n";
		cout << "::::::::::::::: Program Men�s� :::::::::::::::\n";
		cout << "0. Exit \n";
		cout << "1. Yeni Bir Numara Ekleme \n";
		cout << "2. Kay�ttaki B�t�n Numaralar� G�ster \n";
		cout << "3. ID'ye G�re Arama \n";
		cout << "4. �sime G�re Arama \n";
		cout << "5. Telefon Numaras�na G�re Arama \n";
		cout << "6. �stenilen Bir Kay�d� De�i�tirme \n";
		cout << "7. �stenilen Bir Kay�d� ID'ye G�re Silme \n";
		cout << "8. �stenilen Bir Kay�d� �sime G�re Silme \n";
		cout << "Yapmak istedi�iniz Talimat� Giriniz: \n";
		cin >> durum;

		switch (durum)
		{

		case 1:  numaraEkle(); break;
		case 2:	 kay�tG�ster(); break;
		case 3:	 IDArama(); break;
		case 4:  isimArama(); break;
		case 5:	 telArama(); break;
		case 6:	 kay�tD�zenle(); break;
		case 7:  IDkay�tSil(); break;
		case 8:  isimkay�tSil(); break;
		}
	} while (durum);

}

void main() 
{
    setlocale(LC_ALL, "Turkish");
	anamenu();
}