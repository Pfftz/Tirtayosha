#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int top = 0;

struct mahasiswa
{
    int nim;
    string nama;
};

void welcome()
{
    string opening = R"(
  ________  ___________  _______   ____  ____   ______  ___________  
 /"       )("     _   ")/"      \ ("  _||_ " | /" _  "\("     _   ") 
(:   \___/  )__/  \\__/|:        ||   (  ) : |(: ( \___))__/  \\__/  
 \___  \       \\_ /   |_____/   )(:  |  | . ) \/ \        \\_ /     
  __/  \\      |.  |    //      /  \\ \__/ //  //  \ _     |.  |     
 /" \   :)     \:  |   |:  __   \  /\\ __ //\ (:   _) \    \:  |     
(_______/       \__|   |__|  \___)(__________) \_______)    \__|     
                                                                     
)";
    SetConsoleTextAttribute(h, 12);
    cout << opening << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "====================================" << endl;
    cout << " Nama: Abdulhadi Muntashir" << endl;
    cout << " NIM: 3337230041" << endl;
    cout << "====================================" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

bool isEmpty()
{
    return top == 0;
}

bool isFull(int &n)
{
    return top >= n;
}

void enqueue(int &n)
{
    mahasiswa *data = new mahasiswa[n];

    if (isFull(n))
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
            cout << " NIM[0]    : ";
            cin >> data[i].nim;
            cout << " Nama[1]   : ";
            cin >> data[i].nama;
            cout << endl;
        }
        top++;
    }
    void descendant(int &n, mahasiswa data[]);
    descendant(n, data);
}

void descendant(int &n, mahasiswa data[])
{
    int temp;
    string temp2;

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
    void tampil(int &n, mahasiswa data[]);
    tampil(n, data);
}

void tampil(int &n, mahasiswa data[])
{
    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " (NIM: " << data[i].nim;
        cout << " Nama: " << data[i].nama << ") " << endl;
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
    return 0;
}