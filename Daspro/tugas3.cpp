#include <iostream>
using namespace std;

void hitung_gaji(int golongan, int jam_lembur)
{
    // Deklarasi variabel
    int gaji_pokok, transport, lembur, total_gaji;

    // Hitung gaji pokok dan transport
    switch (golongan)
    {
    case 1:
        gaji_pokok = 3000000;
        transport = 1000000;
        break;
    case 2:
        gaji_pokok = 4000000;
        transport = 1500000;
        break;
    case 3:
        gaji_pokok = 5000000;
        transport = 2000000;
        break;
    case 4:
        gaji_pokok = 6000000;
        transport = 2500000;
        break;
    case 5:
        gaji_pokok = 7000000;
        transport = 3000000;
        break;
    default:
        cout << "Golongan tidak valid" << endl;
        return;
    }

    // Hitung lembur
    lembur = jam_lembur * 50000;

    // Hitung total gaji
    total_gaji = gaji_pokok + transport + lembur;

    // Tampilkan hasil perhitungan
    cout << "Gaji Pokok: " << gaji_pokok << endl;
    cout << "Transport: " << transport << endl;
    cout << "Lembur: " << lembur << endl;
    cout << "Total Gaji: " << total_gaji << endl;
}

int main()
{
    // Membaca input golongan dan jam lembur
    int golongan, jam_lembur;
    cout << "Masukkan golongan: ";
    cin >> golongan;
    cout << "Masukkan jam lembur: ";
    cin >> jam_lembur;

    // Menghitung total gaji
    hitung_gaji(golongan, jam_lembur);

    return 0;
}