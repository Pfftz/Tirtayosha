#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nama, mk, grade, sts, gg, nimStr;
    int nilai, nima;

    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nimStr;
    cout << "Masukkan Nilai: ";
    cin >> nilai;
    cout << "Masukkan MK: ";
    cin >> mk;

    cout << "\nNama: " << nama << endl;

    nima = nimStr[nimStr.size() - 1] - '0';

    if (nima % 2 == 0)
    {
        gg = "Genap";
    }
    else
    {
        gg = "Ganjil";
    }
    cout << "NIM: " << nimStr << " " << gg << endl;
    if (mk == "ALPRO" || mk == "alpro")
    {
        sts = "WAJIB";
    }
    else
    {
        sts = "Tidak Wajib";
    }
    if (nilai >= 90)
    {
        grade = "A";
    }
    else if (nilai >= 80 && nilai < 90)
    {
        grade = "A-";
    }
    else if (nilai >= 75 && nilai < 80)
    {
        grade = "B+";
    }
    else if (nilai >= 70 && nilai < 75)
    {
        grade = "B";
    }
    else if (nilai >= 65 && nilai < 70)
    {
        grade = "B-";
    }
    else if (nilai >= 60 && nilai < 65)
    {
        grade = "C";
    }
    else if (nilai >= 55 && nilai < 60)
    {
        grade = "D";
    }
    else
    {
        grade = "E";
    }
    cout << "Nilai: " << grade << endl;
    cout << "MK: " << sts << endl;
}