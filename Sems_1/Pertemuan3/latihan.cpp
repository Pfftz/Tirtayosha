#include <iostream>

using namespace std;

int uts, uas, tugas, hasil_nim;
float nilai_akhir;
string nama;
char nim;

void input()
{
    cout << "Masukkan NIM: ";
    cout << "NIM = A1B2C3010" << endl;
    nim = 'A1B2C3010';
    if (hasil_nim = (int) (nim - '0') % 2 == 0){
        cout << "Nim Genap" << endl;
    }else{
        cout << "Nim Ganjil" << endl;
    }

    cout << "Masukkan Nama: "; 
    getline(cin, nama);
    cout << "Masukkan Nilai UTS: ";
    cin >> uts;
    cout << "Masukkan Nilai UAS: "; 
    cin >> uas;
    cout << "Masukkan Nilai Tugas: ";
    cin >> tugas;
}

void grade()
{
    if (nilai_akhir >= 90)
    {
        cout << "A" << endl;
    }
    else if (nilai_akhir >= 80)
    {
        cout << "A-" << endl;
    }
    else if (nilai_akhir >= 75)
    {
        cout << "B+" << endl;
    }
    else if (nilai_akhir >= 70)
    {
        cout << "B" << endl;
    }
    else if (nilai_akhir >= 65)
    {
        cout << "C+" << endl;
    }
    else if (nilai_akhir >= 60)
    {
        cout << "C" << endl;
    }
    else if (nilai_akhir >= 55)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "E" << endl;
    }
}

int main()
{
    cout << "Program Menghitung Nilai Akhir" << endl;
    cout << "===============================" << endl;
    input();
    cout << "===============================" << endl;
    cout << "NIM: " << "A1B2C3009" << endl;
    cout << "Nama: " << nama << endl;
    cout << endl;
    if (uts <= uas && uts <= tugas)
        cout << "Nilai terkecil adalah: " << uts << endl;
    if (uas <= uts && uas <= tugas)
        cout << "Nilai terkecil adalah: " << uas << endl;
    if (tugas <= uts && tugas <= uas)
        cout << "Nilai terkecil adalah: " << tugas << endl;

    nilai_akhir = (uts + uas + tugas) / 3;

    grade();

    return 0;
}