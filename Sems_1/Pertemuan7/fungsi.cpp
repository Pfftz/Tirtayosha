#include <iostream>
#include <cmath>

using namespace std;

float rumus1(float a, float b)
{
    float hasil;

    hasil = sqrt(pow(a, 2) + pow(b, 2));

    return hasil;
}

float rumus2(float a, float b, float c)
{
    float hasil;

    hasil = pow(b, 2) - (4 * a * c);

    return sqrt(hasil);
}

void menu1()
{
    float a, b, c;
    cout << " Masukkan nilai a: ";
    cin >> a;
    cout << " Masukkan nilai b: ";
    cin >> b;
    cout << " Masukkan nilai c: ";
    cin >> c;
    if (rumus2(a, b, c) > 0)
    {
        cout << " Nilai diskriminan adalah " << rumus2(a, b, c) << endl;
    }
    else
    {
        cout << " Nilai diskriminan tidak boleh negatif" << endl;
    }
    cout << endl;
    rumus1(a, b);
}

int main()
{
    int i = 1, menu;

    do
    {
        cout << "1. Menghitung Phytagoras" << endl;
        cout << "2. Menghitung Diskriminan" << endl;
        cout << "Silahkan pilih menu: ";
        cin >> menu;

        if (menu == 1)
        {
            menu1();
        }
        else if (menu == 2)
        {
            // menu2();
        }
    } while (i > 0);

    return 0;
}