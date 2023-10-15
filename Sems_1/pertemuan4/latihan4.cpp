#include <iostream>
using namespace std;

int main()
{
    double alas, tinggi, luasSegitiga, panjang, lebar, luasPersegiPanjang;
    int pilihan, n;
    bool menu = true;

    cout << "\n====================================" << endl;
    cout << " Main Menu" << endl;
    cout << " 1. Menghitung Bilangan Prima" << endl;
    cout << " 2. Menghitung faktorial" << endl;
    cout << " 3. Menghitung luas persegi panjang" << endl;
    cout << " 4. Menghitung luas segitiga" << endl;
    cout << " 5. Nested Loop" << endl;
    cout << " 6. Nested Loop Terbalik" << endl;
    cout << " 7. Prima Checker" << endl;
    cout << " 8. Keluar" << endl;
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
            int prima;
            cout << " Masukkan batas bilangan prima: ";
            cin >> prima;
            for (int i = 2; i < prima; i++)
            {
                int bil = 0;
                for (int j = 1; j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        bil += 1;
                    }
                }
                if (bil == 2)
                {
                    cout << "( " << i << " )";
                }
            }
            cout << endl;
            break;
        case 2:
        {
            long double factorial = 1;
            cout << " Masukkan Bilangan: ";
            cin >> n;
            if (n < 0)
                cout << " Faktorial hanya didefinisikan untuk bilangan bulat positif.";
            else
            {
                for (int i = 1; i <= n; ++i)
                {
                    factorial *= i;
                }
                cout << " Factorial dari " << n << " = " << factorial;
            }
            cout << endl;
            break;
        }
        case 3:
            cout << " Masukkan panjang: ";
            cin >> panjang;

            cout << " Masukkan lebar: ";
            cin >> lebar;

            luasPersegiPanjang = panjang * lebar;

            cout << " Luas persegi panjang adalah: " << luasPersegiPanjang << endl;
            cout << endl;
            break;
        case 4:
            cout << " Masukkan panjang alas: ";
            cin >> alas;

            cout << " Masukkan tinggi: ";
            cin >> tinggi;

            luasSegitiga = (alas * tinggi) / 2;

            cout << " Luas segitiga adalah: " << luasSegitiga << endl;
            cout << endl;
            break;
        case 5:
            cout << " Bintang Kecil ke besar" << endl;
            cout << " Masukkan Panjang Bintang: ";
            cin >> n;
            cout << endl;
            for (int x = 0; x <= n; x++)
            {
                for (int y = 0; y < x; y++)
                {
                    cout << " *";
                }
                cout << endl;
            }
            cout << endl;
            break;
        case 6:
        {
            int b;
            cout << "Masukkan bintang: ";
            cin >> b;
            cout << endl;
            for (int i = b; i >= 1; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    cout << " * ";
                }
                cout << endl;
            }
            cout << endl;
            break;
        }
        case 7:
        {
            int n;
            bool isPrime = true;
            cout << " Masukkan Bilangan : ";
            cin >> n;
            cout << endl;
            for (int i = 2; i <= n - 1; i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << " " << n << " adalah bilangan prima" << endl;
            }
            else
            {
                cout << " " << n << " bukan bilangan prima" << endl;
            }
            cout << endl;
            break;
        }
        case 8:
            cout << " <<program selesai>>" << endl;
            exit(0);
        default:
            cout << " Pilihan tidak valid" << endl;
            break;
        }
    }
    return 0;
}