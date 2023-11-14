#include <iostream>
#include <queue>

using namespace std;

struct mahasiswa
{
    int nim;
    string nama;
};

struct compareNim
{
    bool operator()(const mahasiswa &a, const mahasiswa &b)
    {
        return a.nim > b.nim;
    }
};

int main()
{
    int n;
    cout << " Masukkan nilai n: ";
    cin >> n;

    priority_queue<mahasiswa, vector<mahasiswa>, compareNim> data;

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