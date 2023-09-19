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

    while (menu)
    {
        cout << "Menu:" << endl;
        cout << "1. Menghitung luas segitiga" << endl;
        cout << "2. Menghitung luas persegi panjang" << endl;
        cout << "3. Menghitung faktorial" << endl;
        cout << "4. Nested Looping" << endl;
        cout << "5. Nested Looping Terbalik" << endl;
        cout << "6. Nested Looping Dari Kanan" << endl;
        cout << "7. Nested Looping Dari Kanan Terbalik" << endl;
        cout << "8. Membalik Bilangan" << endl;
        cout << "9. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan panjang alas segitiga: ";
            cin >> alas;

            cout << "Masukkan tinggi segitiga: ";
            cin >> tinggi;

            luasSegitiga = (alas * tinggi) / 2;

            cout << "Luas segitiga adalah: " << luasSegitiga << endl;
            system("cls");
            break;
        case 2:
            cout << "Masukkan panjang persegi panjang: ";
            cin >> panjang;

            cout << "Masukkan lebar persegi panjang: ";
            cin >> lebar;

            luasPersegiPanjang = panjang * lebar;

            cout << "Luas persegi panjang adalah: " << luasPersegiPanjang << endl;
            system("cls");
            break;
        case 3:
            cout << "Masukkan bilangan bulat positif untuk menghitung faktorial: ";
            cin >> n;

            if (n < 0)
                cout << "Faktorial hanya didefinisikan untuk bilangan bulat positif." << endl;
            else
                cout << "Faktorial dari " << n << " adalah " << factorial(n) << endl;
            system("cls");
            break;
        case 4:
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            system("cls");
            break;
        case 5:
            for (int i = 5; i >= 1; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            system("cls");
            break;
        case 6:
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5 - i; j++)
                {
                    cout << "  ";
                }
                for (int k = 1; k <= i; k++)
                {
                    cout << "* ";
                }

                cout << endl;
            }
            system("cls");
            break;
        case 7:
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    cout << "  ";
                }
                for (int k = i; k <= 5; k++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            system("cls");
            break;
        case 8:
            long m, d, n = 0;
            cout << "Masukkan bilangan : ";
            cin >> m;
            while (m > 0)
            {
                d = m % 10;
                m /= 10;
                n = 10 * n + d;
            }
            cout << "Hasil pembalikan bilangan adalah : " << n;
            system("cls");
            break;
        case 9:
            cout << "program selesai" << endl;
            system("cls");
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            system("cls");
            break;
        }
    }

    return 0;
}