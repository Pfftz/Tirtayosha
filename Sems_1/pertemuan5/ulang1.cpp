#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    double alas, tinggi, luasSegitiga, panjang, lebar, luasPersegiPanjang;
    int pilihan, n;
    bool menu = true;

    cout << "\n====================================" << endl;
    cout << " Menu:" << endl;
    cout << " 1. Menghitung Bilangan Prima" << endl;
    cout << " 2. Menghitung faktorial" << endl;
    cout << " 3. Menghitung luas persegi panjang" << endl;
    cout << " 4. Menghitung luas segitiga" << endl;
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
            cout << " Masukkan bilangan bulat positif untuk menghitung faktorial: ";
            cin >> n;

            if (n < 0)
                cout << " Faktorial hanya didefinisikan untuk bilangan bulat positif." << endl;
            else
                cout << " Faktorial dari " << n << " adalah " << factorial(n) << endl;

            cout << endl;
            break;
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
            cout << " <<program selesai>>" << endl;
            exit(0);
        default:
            cout << " Pilihan tidak valid" << endl;
            break;
        }
    }
    return 0;
}