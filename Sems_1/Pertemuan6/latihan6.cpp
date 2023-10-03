#include <iostream>
using namespace std;

int main()
{
    int pilihan;
    bool menu = true;
    
    cout << "\n====================================" << endl;
    cout << " Main Menu" << endl;
    cout << " 1. Input Nilai Matrix" << endl;
    cout << " 2. Matrix kali" << endl;
    cout << " 3. Rata-rata" << endl;
    cout << " 4. Hilang" << endl;
    cout << " 5. Keluar" << endl;
    cout << "====================================" << endl;

    while (menu)
    {
        cout << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
        case 1:
        {
            int baris, kolom;

            cout << " Masukkan jumlah baris: ";
            cin >> baris;
            cout << " Masukkan jumlah kolom: ";
            cin >> kolom;

            int data[baris][kolom];

            for (int i = 0; i < baris; i++)
            {
                for (int j = 0; j < kolom; j++)
                {
                    cout << " Data [" << i << "][" << j << "] : ";
                    cin >> data[i][j];
                }
            }

            cout << endl;
            cout << " Data yang telah dimasukkan: " << endl;

            for (int q = 0; q < baris; q++)
            {
                for (int e = 0; e < kolom; e++)
                {
                    cout << " Data Ke-" << (q * kolom + e) + 1 << ": " << data[q][e] << endl;
                }
            }

            cout << endl;
            break;
        }
        case 2:
        {
            int baris, kolom, kali;

            cout << " Masukkan jumlah baris: ";
            cin >> baris;
            cout << " Masukkan jumlah kolom: ";
            cin >> kolom;
            cout << " Masukkan jumlah kali: ";
            cin >> kali;

            int data[baris][kolom];

            for (int i = 0; i < baris; i++)
            {
                for (int j = 0; j < kolom; j++)
                {
                    cout << " Data [" << i << "][" << j << "] : ";
                    cin >> data[i][j];
                }
            }

            cout << endl;
            cout << " Data yang telah dimasukkan: " << endl;

            for (int q = 0; q < baris; q++)
            {
                for (int e = 0; e < kolom; e++)
                {
                    cout << " Data Ke-" << (q * kolom + e) + 1 << ": " << data[q][e] * kali << endl;
                }
            }

            cout << endl;
            break;
        }
        case 3:
        {
            int baris, kolom, counter = 0;
            float jumlah = 0, rata;

            cout << " Masukkan jumlah baris: ";
            cin >> baris;
            cout << " Masukkan jumlah kolom: ";
            cin >> kolom;

            int data[baris][kolom];

            for (int i = 0; i < baris; i++)
            {
                for (int j = 0; j < kolom; j++)
                {
                    cout << " Data [" << i << "][" << j << "] : ";
                    cin >> data[i][j];
                }
            }

            cout << endl;
            cout << " Data yang telah dimasukkan: " << endl;

            for (int q = 0; q < baris; q++)
            {
                for (int e = 0; e < kolom; e++)
                {
                    cout << " Data Ke-" << (q * kolom + e) + 1 << ": " << data[q][e] << endl;
                    jumlah += data[q][e];
                    counter++;
                }
            }
            rata = jumlah / counter;
            cout << " Jumlah data: " << jumlah << endl;
            cout << " Rata-rata data: " << rata << endl;

            cout << endl;
            break;
        }
        case 4:
        {
            int data[2];
            system("cls");
            for (int i = 0; i < 2; i++)
            {
                cout << "\n====================================" << endl;
                cout << " Main Menu" << endl;
                cout << " 1. Input Nilai Matrix" << endl;
                cout << " 2. Matrix kali" << endl;
                cout << " 3. Rata-rata" << endl;
                cout << " 4. Hilang" << endl;
                cout << " 5. Keluar" << endl;
                cout << "====================================" << endl;
                cout << endl;
                cout << " Masukkan pilihan: 4";
                cout << endl;
                cout << " Masukkan Nilai : ";
                cin >> data[i];
                system("cls");
            }
            cout << "\n====================================" << endl;
            cout << " Main Menu" << endl;
            cout << " 1. Input Nilai Matrix" << endl;
            cout << " 2. Matrix kali" << endl;
            cout << " 3. Rata-rata" << endl;
            cout << " 4. Hilang" << endl;
            cout << " 5. Keluar" << endl;
            cout << "====================================" << endl;
            cout << endl;
            cout << " Masukkan pilihan: 4";
            cout << endl;

            int hasil = 1;
            string formula = " Hasil: ";
            for (int i = 0; i < 2; i++)
            {
                hasil *= data[i];
                formula += to_string(data[i]);
                if (i < 2 - 1)
                {
                    formula += " * ";
                }
            }
            formula += " = " + to_string(hasil);

            cout << formula << endl;

            cout << endl;
            break;
        }
        case 5:
            cout << " <<program selesai>>" << endl;
            exit(0);
        default:
            cout << " Pilihan tidak valid" << endl;
            break;
        }
    }
    return 0;
}