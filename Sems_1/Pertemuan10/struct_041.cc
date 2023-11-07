#include <iostream>
#include <iomanip>

using namespace std;

struct mahasiswa
{
    int nim;
    string nama;
};

struct parkir
{
    int jam, menit, detik;
    int selisih, biaya;
};

void menu1(int *pn)
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;

    mahasiswa *data = new mahasiswa[*pn];

    int temp;
    string temp2;
    for (int i = 0; i < *pn; i++)
    {
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> data[i].nim;
        cout << " Nama[1]   : ";
        cin >> data[i].nama;
        cout << endl;
    }

    for (int i = 0; i < *pn; i++)
    {
        for (int j = i + 1; j < *pn; j++)
        {
            if (data[i].nim < data[j].nim)
            {
                temp = data[i].nim;        // nim[i]
                data[i].nim = data[j].nim; // nim[i] = nim[j]
                data[j].nim = temp;        // nim[j] = temp

                temp2 = data[i].nama;        // nama[i]
                data[i].nama = data[j].nama; // nama[i] = nama[j]
                data[j].nama = temp2;        // nama[j] = temp2
            }
        }
    }

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    for (int i = 0; i < *pn; i++)
    {
        cout << " (NIM: " << data[i].nim;
        cout << " Nama: " << data[i].nama << ") " << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
}

void menu2()
{
    parkir arrived, departure;
    cout << " Input arrived time" << endl;
    cout << " Hour: ";
    cin >> arrived.jam;
    cout << " Minute: ";
    cin >> arrived.menit;
    cout << " Second: ";
    cin >> arrived.detik;
    cout << endl;
    cout << " Input departure time" << endl;
    cout << " Hour: ";
    cin >> departure.jam;
    cout << " Minute: ";
    cin >> departure.menit;
    cout << " Second: ";
    cin >> departure.detik;
    cout << endl;

    if (departure.detik < arrived.detik)
    {
        departure.detik += 60;
        departure.menit--;
    }
    else if (departure.menit < arrived.menit)
    {
        departure.menit += 60;
        departure.jam--;
    }
    else if (departure.jam < arrived.jam)
    {
        departure.jam += 24;
    }
    else if (departure.jam == arrived.jam && departure.menit == arrived.menit && departure.detik == arrived.detik)
    {
        cout << " Arrived time = " << arrived.jam << ":" << arrived.menit << ":" << arrived.detik << endl;
        cout << " Departure time = " << departure.jam << ":" << departure.menit << ":" << departure.detik << endl;
        cout << " Parking time = 0:0:0" << endl;
        cout << " Parking fee = 0" << endl;
        exit(0);
    }

    cout << " Arrived time = "
         << std::setw(2) << std::setfill('0') << arrived.jam << ":"
         << std::setw(2) << std::setfill('0') << arrived.menit << ":"
         << std::setw(2) << std::setfill('0') << arrived.detik << endl;

    cout << " Departure time = "
         << std::setw(2) << std::setfill('0') << departure.jam << ":"
         << std::setw(2) << std::setfill('0') << departure.menit << ":"
         << std::setw(2) << std::setfill('0') << departure.detik << endl;
    departure.jam -= arrived.jam;
    departure.menit -= arrived.menit;
    departure.detik -= arrived.detik;
    cout << " Parking time = " << departure.jam << ":" << departure.menit << ":" << departure.detik << endl;
    departure.selisih = departure.jam * 3600 + departure.menit * 60 + departure.detik;
    if (departure.selisih <= 3600)
    {
        departure.biaya = 3000;
    }
    else
    {
        departure.biaya = 3000;
        int extraHours = departure.selisih / 3600; // calculate the number of extra hours
        departure.biaya += extraHours * 3000;      // add 3000 for each extra hour
    }

    cout << " Parking fee = " << departure.biaya << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu3()
{
    cout << " Terima kasih telah menggunakan program ini" << endl;
    exit(0);
}

int main()
{
    int pilih, n;
    bool menu = true;
    while (menu)
    {
        cout << "\n====================================" << endl;
        cout << " Main Menu" << endl;
        cout << " 1. Mengurutkan nim mahasiswa descending" << endl;
        cout << " 2. Mencari Jumlah biaya parkir dari selisih datang dan pergi" << endl;
        cout << " 3. Keluar" << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilih;
        cout << endl;
        switch (pilih)
        {
        case 1:
            menu1(&n);
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        default:
            cout << " Pilihan tidak tersedia" << endl;
            break;
        }
    }
    return 0;
}
