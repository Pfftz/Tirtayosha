#include <iostream>
#include <queue>
#include <string>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int top = 0;

struct mahasiswa
{
    int nim;
    string nama;
};

struct compareNim
{
    bool operator()(const mahasiswa &a, const mahasiswa &b)
    {
        return a.nim < b.nim; // change to '>' for ascending order
    }
};

priority_queue<mahasiswa, vector<mahasiswa>, compareNim> value;
;

void welcome()
{
    string opening = R"(
:'#######::'##::::'##:'########:'##::::'##:'########:
'##.... ##: ##:::: ##: ##.....:: ##:::: ##: ##.....::
 ##:::: ##: ##:::: ##: ##::::::: ##:::: ##: ##:::::::
 ##:::: ##: ##:::: ##: ######::: ##:::: ##: ######:::
 ##:'## ##: ##:::: ##: ##...:::: ##:::: ##: ##...::::
 ##:.. ##:: ##:::: ##: ##::::::: ##:::: ##: ##:::::::
. ##### ##:. #######:: ########:. #######:: ########:
:.....:..:::.......:::........:::.......:::........::
)";
    SetConsoleTextAttribute(h, 13);
    cout << opening << endl;
    cout << "====================================" << endl;
    cout << " Nama: Abdulhadi Muntashir" << endl;
    cout << " NIM: 3337230041" << endl;
    cout << "====================================" << endl;
    SetConsoleTextAttribute(h, 7);
    cout << endl;
    system("pause");
    system("cls");
}

void enqueue(int n)
{
    for (int i = 0; i < n; i++)
    {
        mahasiswa mhs;
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> mhs.nim;
        cout << " Nama[1]   : ";
        cin >> mhs.nama;
        cout << endl;
        value.push(mhs);
    }
}

void tampil()
{
    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    while (!value.empty())
    {
        mahasiswa mhs = value.top();
        value.pop();
        cout << " (NIM: " << mhs.nim;
        cout << " Nama: " << mhs.nama << ") " << endl;
    }
    cout << endl;
}

int main()
{
    welcome();
    int n;
    cout << " Masukkan nilai n: ";
    cin >> n;
    enqueue(n);
    tampil();
    return 0;
}