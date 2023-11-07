// Struct
#include <iostream>

using namespace std;

struct mahasiswa
{
    string nim;
    string nama;
    string jurusan;
    int nilai;
};

void stroke1(){
    /*
    data.nim = "23214322";
    data.nama = "Bayu";
    data.jurusan = "Teknik Informatika";
    data.nilai = 86;

    cout << "Nim: " << data.nim << endl;
    cout << "nama: " << data.nama << endl;
    cout << "jurusan: " << data.jurusan << endl;
    cout << "nilai: " << data.nilai << endl;
    */
}

int main()
{

    int jumlahData;
    cout << "Masukkan jumlah data: ";
    cin >> jumlahData;
    mahasiswa data[jumlahData];

    for (int i = 0; i < jumlahData; i++)
    {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nim: ";
        cin >> data[i].nim;
        cout << "Masukkan Nama: ";
        cin >> data[i].nama;
        cout << "Masukkan Jurusan: ";
        cin >> data[i].jurusan;
        cout << "Masukkan Nilai: ";
        cin >> data[i].nilai;
    }
    cout << endl;

    for (int i = 0; i < jumlahData; i++)
    {
        cout << "Tampilan Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nim: " << data[i].nim << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Jurusan: " << data[i].jurusan << endl;
        cout << "Nilai: " << data[i].nilai << endl;
    }
    return 0;
}