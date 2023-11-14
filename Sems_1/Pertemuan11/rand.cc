#include <iostream>

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

    mahasiswa *data = new mahasiswa[n];

    int temp;
    string temp2;
    for (int i = 0; i < n; i++)
    {
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> data[i].nim;
        cout << " Nama[1]   : ";
        cin >> data[i].nama;
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (data[i].nim < data[j].nim)
            {
                temp = data[i].nim;        // nim[i]
                data[i].nim = data[j].nim; // nim[i] = nim[j]
                data[j].nim = temp;        // nim[j] = temp

                temp2 = data[i].nama;        // nama[i]
                data[i].nama = data[j].nama; // nama[i] = nama[j]
                data[j].nama = temp2;        // nama[j] = temp2
            }
        }
    }

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " (NIM: " << data[i].nim;
        cout << " Nama: " << data[i].nama << ") " << endl;
    }

    delete[] data;

    cout << endl;
}