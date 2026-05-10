#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct Buku {
  string judul, penulis, ISBN;
};

string namaFile = "data.txt";

string ReplaceUnderscore (string s); // mengganti setiap "_" yang ada pada file menjadi " "
string ReplaceSpasi (string s); // mengganti setiap " " yang ada pada file menjadi "_"

/*

  kenapa setiap data jika ingin diinput, setiap " " harus diganti dengan "_"?
  karena program akan membaca " " menjadi data yang berbeda, maka untuk mengatisipasi hal tersebut, setiap data yang ada spasinya diganti dengan underscore.

  contoh : 
  user ingin memasukkan data berupa "Algoritma Pemrograman", itu harus diubah menjadi "Algoritma_Pemrograman" terlebih dahulu.
  jika tidak diganti, maka program akan membaca "Algoritma" dan "Pemrograman" bukan "Algoritma Pemrograman".

*/

void BacaData (); // Contoh penggunaan ifstream
void TambahData (Buku data); // Contoh penggunaan ofstream serta ios::app

int main () {
  int pil;
  bool ulang = 1;
  Buku buku;

  while (ulang)
  {
    system("cls");
    cout << "Selamat Datang di Toko Buku!\n";
    cout << "[1] Tambah Buku\n";
    cout << "[2] Lihat Buku\n";
    cout << "[3] Keluar\n";
    cout << "Pilihan : ";
    cin >> pil;
    
    switch (pil)
    {
      case 1:
      system("cls");
      
      cin.ignore();
      cout << "Menu Tambah Buku\n\n";
      cout << "Judul Buku : ";
      getline(cin, buku.judul);

      cout << "Penulis Buku : ";
      getline(cin, buku.penulis);

      cout << "ISBN : ";
      getline(cin, buku.ISBN);

      TambahData(buku);
      cout << "\nBuku Berhasil di Masukkan\n";
      cout << "Tekan apa saja untuk melanjutkan...";
      getch();
      break;
    case 2:
      system("cls");
      BacaData();
      cout << "Tekan apa saja untuk melanjutkan...";
      getch();
      break;
    case 3:
      cout << "\nSelamat Tinggal.";
      ulang = 0;
      break;
    default:
      cout << "\nPilihan tidak ada...\n";
      cout << "Tekan apa saja untuk melanjutkan...";
      getch();
      break;
    }
  }
  
}

// Algoritma untuk mengganti " " menjadi "_"
string ReplaceSpasi (string s) {
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ')
    {
      s.replace(i, 1, 1, '_'); // index keberapa, berapa banyak karakter yang mau diganti, berapa banyak karakter yang mau diinput, karakter pengganti
    }
  }
  return s;
}

// Algoritma untuk mengganti "_" menjadi " "
string ReplaceUnderscore (string s) {
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '_') // jika ketemu "_", maka 
    {
      s.replace(i, 1, 1, ' '); // index keberapa, berapa banyak karakter yang mau diganti, berapa banyak karakter yang mau diinput, karakter pengganti
    }
  }
  return s;
}

void BacaData () {
  ifstream DataBase(namaFile); // perintah membaca file
  if(DataBase.is_open())
  {
    cout << "Data Buku : \n\n";
    int i = 1;
    string judul, penulis, ISBN;
    while(DataBase >> judul >> penulis >> ISBN) // mengeluarkan setiap data perbaris
    {
      judul = ReplaceUnderscore(judul);
      penulis = ReplaceUnderscore(penulis);
      cout << "Data ke - " << i << endl << endl;
      cout << "Judul Buku : " << judul << endl;
      cout << "Penulis Buku : " << penulis << endl;
      cout << "ISBN Buku : " << ISBN << endl << endl;

      i++;
    }
    DataBase.close();
  }else{
    cout << "Tidak Bisa Dibuka\n"; 
  }
}

void TambahData (Buku data) {
  ofstream DataBase(namaFile, ios::app); // perintah menginput data di akhir (tanpa harus menghapus data keseluruhan)
  if(DataBase.is_open())
  {
    string penulis = ReplaceSpasi(data.penulis);
    string judul = ReplaceSpasi(data.judul);
    string ISBN = data.ISBN;
    DataBase << judul << " " << penulis << " " << ISBN << endl; // menginput data
    DataBase.close();
  }
  else
  {
    cout << "Tidak Bisa Dibuka\n";  
  }
  return;
}