#include <iostream>
#include <stack>

using namespace std;

struct mahasiswa
{
    int nim;
    string nama;
};

int main()
{
    int n;
    cout << " Masukkan nilai n: ";
    cin >> n;

    stack <mahasiswa> data;

    for (int i = 0; i < n; i++)
    {
        mahasiswa mhs;
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> mhs.nim;
        cout << " Nama[1]   : ";
        cin >> mhs.nama;
        cout << endl;
        data.push(mhs);
    }

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    while (!data.empty())
    {
        mahasiswa mhs = data.top();
        data.pop();
        cout << " (NIM: " << mhs.nim;
        cout << " Nama: " << mhs.nama << ") " << endl;
    }

    cout << endl;
    return 0;
}