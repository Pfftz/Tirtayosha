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

queue<mahasiswa> value;

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
    if (value.size() >= n)
    {
        cout << "Queue is full" << endl;
        return;
        system("pause");
    }
    mahasiswa mhs;
    cout << " Masukkan data mahasiswa: " << endl;
    cout << " NIM[0]    : ";
    cin >> mhs.nim;
    cout << " Nama[1]   : ";
    cin >> mhs.nama;
    cout << endl;
    value.push(mhs);
}

void dequeue()
{
    if (value.empty())
    {
        cout << "Queue is empty" << endl;
        return;
        system("pause");
    }

    value.pop();
    cout << endl;
}

void tampil(int n)
{
    mahasiswa *data = new mahasiswa[n];
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

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    auto copy = value; // Create a copy of the priority queue
    if (copy.empty())
    {
        cout << " Queue is empty\n\n"
             << endl;
        return;
        system("pause");
    }
    int i = 1;
    while (!copy.empty())
    {
        mahasiswa mhs = copy.front();
        copy.pop();
        cout << " " << i << ". (NIM: " << mhs.nim;
        cout << " Nama: " << mhs.nama << ") " << endl;
        i++;
    }
    cout << endl;
    delete[] data;
}

void menu3()
{
    cout << "--- Front, back, size ---\n\n";
    cout << " Front: \n"
         << " (NIM: " << value.front().nim << " Nama: " << value.front().nama << ") " << endl;
    cout << " Back: \n"
         << " (NIM: " << value.back().nim << " Nama: " << value.back().nama << ") " << endl;
    cout << " Size: " << value.size() << endl;
    cout << "------------------------\n\n";
    cout << endl;
    system("pause");
}

int main()
{
    welcome();
    int n, menu;
    bool loop = true;

    cout << "\n\n Masukkan nilai n: ";
    cin >> n;
    cout << endl;
    while (loop)
    {
        system("cls");
        tampil(n);
        cout << " 1. Menu enqueue" << endl; // Memasukkan data ke antrian
        cout << " 2. Menu dequeue" << endl; // Menghapus top dari data antrian
        cout << " 3. Front, back, size" << endl;
        cout << " 4. Exit" << endl; // Keluar dari program
        cout << " Silahkan masukkan menu: ";
        cin >> menu;
        cout << endl;
        switch (menu)
        {
        case 1:
            system("cls");
            enqueue(n);
            break;
        case 2:
            system("cls");
            dequeue();
            break;
        case 3:
            system("cls");

            break;
        case 4:
            SetConsoleTextAttribute(h, 5);
            cout << "   ______    __          __        ______    " << endl;
            cout << "  /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
            cout << " (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
            cout << "  \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
            cout << "  //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
            cout << " (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
            cout << "  \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
            exit(0);
        default:
            cout << "Menu tidak tersedia" << endl;
            system("pause");
            break;
        }
    }
    return 0;
}