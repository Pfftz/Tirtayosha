#include <iostream>

using namespace std;

int main()
{
    int harga;
    float diskon, total;
    char kode;

    cout << "Masukkan harga barang: ";
    cin >> harga;
    cout << "Masukkan kode diskon: ";
    cin >> kode;
    cout << endl;
    switch (kode)
    {
    case 'H':
        diskon = 0.5 * harga;
        total = harga - diskon;
        cout << "\nharga asli = " << harga << "\ndiskon = " << diskon << "\nTotal harga: " << total << endl;
        break;

    case 'F':
        diskon = 0.4 * harga;
        total = harga - diskon;
        cout << "\nharga asli = " << harga << "\ndiskon = " << diskon << "\nTotal harga: " << total << endl;
        break;

    case 'T':
        diskon = 0.33 * harga;
        total = harga - diskon;
        cout << "\nharga asli = " << harga << "\ndiskon = " << diskon << "\nTotal harga: " << total << endl;
        break;

    case 'Q':
        diskon = 0.25 * harga;
        total = harga - diskon;
        cout << "\nharga asli = " << harga << "\ndiskon = " << diskon << "\nTotal harga: " << total << endl;
        break;

    case 'Z':
        cout << "Tidak ada diskon" << endl;
        break;

    default:
        cout << "Kode diskon salah" << endl;
        break;
    }
    return 0;
}