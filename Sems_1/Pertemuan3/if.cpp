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

    cout << "\nMasukkan nilai: ";
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
    cout << "\nMasukkan golongan: ";
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
    cout << "\nMasukkan nilai a: ";
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

    else if (b > c)
        max = b;
    else
        max = c;

    cout << "Maksimum adalah: " << max << endl;
}

void cabang5()
{
    int a, b, c, min;
    cout << "\nMasukkan nilai a: ";
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
    cout << "\nMasukkan nilai a: ";
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
    cout << "\nApakah anda ingin keluar? (Y/N): ";
    cin >> jawab;

    if (jawab == 'Y' || jawab == 'y')
        cout << "Anda keluar dari program" << endl;
    else
        cout << "Maaf, anda uncertain..." << endl;
}

void cabang8()
{
    string jawab;
    cout << "\nApakah anda ingin keluar? (Y/N): ";
    cin >> jawab;

    if (jawab == "Yakin" || jawab == "yakin")
        cout << "OK, anda yakin" << endl;
    else
        cout << "Maaf, anda uncertain..." << endl;
}

void cabang9()
{
    // cara simple if else
    char status;
    int grade;
    cout << "\nMasukkan nilai: ";
    cin >> grade;

    // mendapatkan status pelajar
    status = (grade >= 60) ? 'L' : 'G'; // ? = if, : = else
    // print status
    cout << "Status: " << status << endl;
}

void cabang10()
{
    // cara simple if else
    string status;
    int grade;
    cout << "\nMasukkan nilai: ";
    cin >> grade;

    // mendapatkan status pelajar
    status = (grade >= 60) ? "L" : "G"; // ? = if, : = else
    // print status
    cout << "Status: " << status << endl;
}

void cabang11()
{
    int m = 26, n = 82;

    int min = (m < n) ? m : n;
    cout << "Nilai terkecil adalah: " << min << endl;
}

void cabang12()
{
    int m = 100, n = 4;

    int max = (m > n) ? m : n;
    cout << "Nilai terbesar adalah: " << max << endl;
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
    // cout << endl;
    // cabang6();
    // cout << endl;
    // cabang7();
    // cout << endl;
    // cabang8();
    // cout << endl;
    // cabang9();
    // cout << endl;
    // cabang10();
    // cabang11();
    // cout << endl;
    // cabang12();

    return 0;
}