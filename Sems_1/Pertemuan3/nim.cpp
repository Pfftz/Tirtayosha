#include <iostream>

using namespace std;

int uts, uas, tugas, hasil_nim;
char nim;

int main()
{
cout << "Masukkan NIM: ";
cin >> nim;
hasil_nim = nim % 2;
if (hasil_nim == 0)
{
    cout << "NIM Genap" << endl;
}
else
{
    cout << "NIM Ganjil" << endl;
}
}