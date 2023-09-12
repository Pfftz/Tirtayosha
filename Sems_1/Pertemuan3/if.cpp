#include <iostream>

using namespace std;

void cabang()
{
    // IF
    int nilai;

    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 90)
    {
        cout << "Nilai angka: A" << endl;
    }
    if (nilai < 90)
    {
        cout << "Nilai angka: B" << endl;
    }
    else
    {
        cout << "Maaf anda tidak lulus" << endl;
    }
}

void cabang2()
{
    // IF
    int nilai;

    cout << "\n\nMasukkan nilai: ";
    cin >> nilai;

    if (nilai % 2 == 0)
    {
        cout << "Nilai" << nilai << "adalah Nilai genap" << endl;
    }
    else
    {
        cout << "Nilai" << nilai << "adalah Nilai ganjil" << endl;
    }
}

void cabang3()
{
    // SWITCH
    int gol;
    cout << "Masukkan golongan: ";
    cin >> gol;

    switch (gol)
    {
    case 1:
        cout << "Gaji = 100" << endl;
        break;
    case 2:
        cout << "Gaji = 200" << endl;
        break;
    case 3:
        cout << "Gaji = 300" << endl;
        break;

    default:
        cout << "Gologan salah" << endl;
        break;
    }
}

void cabang4()
{
    int a, b, c, max;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    if (a > b)
        if (a > c)
            max = a;
        else
            max = c;

    else

        if (b > c)
        max = b;
    else
        max = c;

    cout << "Maksimum adalah: " << max << endl;
}

void cabang5()
{
    int a, b, c, min;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    if (a < b)
        if (a < c)
            min = a;
        else
            min = c;

    else

        if (b < c)
        min = b;
    else
        min = c;

    cout << "Minimum adalah: " << min << endl;
}

void cabang6()
{
    int a, b, c;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    if (a >= b && a >= c)
        cout << "Nilai terbesar adalah: " << a << endl;
    if (b >= a && b >= c)
        cout << "Nilai terbesar adalah: " << b << endl;
    if (c >= a && c >= b)
        cout << "Nilai terbesar adalah: " << c << endl;
}

void cabang7()
{
    char jawab;
    cout << "Apakah anda ingin keluar? (Y/N): ";
    cin >> jawab;

    if (jawab == 'Y' || jawab == 'y')
        cout << "Anda keluar dari program" << endl;
    else
        cout << "Maaf, anda uncertain..." << endl;
}

int main()
{
    // cabang();
    // cout << endl;
    // cabang2();
    // cout << endl;
    // cabang3();
    // cout << endl;
    // cabang4();
    // cout << endl;
    // cabang5();
    // cabang6();
    cabang7();
    return 0;
}