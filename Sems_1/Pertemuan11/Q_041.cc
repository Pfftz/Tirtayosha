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

void enqueue(size_t n)
{
    if (value.size() >= n)
    {
        cout << "Queue is full" << endl;
        system("pause");
        return;
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
    value.pop();
    cout << endl;
}

void tampil(int n)
{
    mahasiswa *data = new mahasiswa[n];
    int temp, i = 0;
    string temp2;

    if (value.empty())
    {
        cout << " Queue is empty" << endl;
        return;
    }
    else
    {
        // Create a copy of the queue
        queue<mahasiswa> copy = value;

        // Copy elements from the queue to the array
        while (!copy.empty())
        {
            data[i] = copy.front();
            copy.pop();
            i++;
        }

        cout << " Queue sebelum diurutkan berdasarkan NIM adalah: " << endl;
        for (int k = 0; k < i; k++)
        {
            cout << " " << (k + 1) << ". (NIM: " << data[k].nim;
            cout << " Nama: " << data[k].nama << ") " << endl;
        }
        cout << endl;

        // Sort the array
        for (int k = 0; k < i; k++)
        {
            for (int j = k + 1; j < i; j++)
            {
                if (data[k].nim < data[j].nim)
                {
                    temp = data[k].nim;
                    data[k].nim = data[j].nim;
                    data[j].nim = temp;

                    temp2 = data[k].nama;
                    data[k].nama = data[j].nama;
                    data[j].nama = temp2;
                }
            }
        }

        // Print the sorted elements
        cout << " Queue setelah diurutkan berdasarkan NIM adalah: " << endl;
        for (int k = 0; k < i; k++)
        {
            cout << " " << (k + 1) << ". (NIM: " << data[k].nim;
            cout << " Nama: " << data[k].nama << ") " << endl;
        }
    }

    delete[] data;
}

void menu3()
{
    SetConsoleTextAttribute(h, 10);
    cout << "--- Front, back, size ---\n\n";
    cout << " Front: \n"
         << " (NIM: " << value.front().nim << " Nama: " << value.front().nama << ") " << endl;
    cout << " Back: \n"
         << " (NIM: " << value.back().nim << " Nama: " << value.back().nama << ") " << endl;
    cout << " Size: " << value.size() << endl;
    cout << "------------------------\n\n";
    SetConsoleTextAttribute(h, 7);
    cout << endl;
    system("pause");
}

int main()
{
    welcome();
    int n, menu;
    bool loop = true;

    cout << "\n\n ================================================" << endl;
    cout << " Masukkan jumlah mahasiswa yang ingin diinput : ";
    cin >> n;
    cout << " ================================================" << endl;
    cout << endl;
    system("pause");
    while (loop)
    {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << " +----------------------------------------------+" << endl;
        tampil(n);
        cout << " +----------------------------------------------+\n"
             << endl;
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
            menu3();
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