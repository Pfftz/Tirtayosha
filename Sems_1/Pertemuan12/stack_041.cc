#include <iostream>
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

mahasiswa *value;

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

bool isEmpty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(int &max)
{
    if (top >= max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int n)
{
    if (!isFull(n))
    {
        cout << " Masukkan data mahasiswa: " << endl;
        cout << " NIM[0]    : ";
        cin >> value[top].nim; // change this to value[top].nim
        cout << " Nama[1]   : ";
        cin >> value[top].nama; // change this to value[top].nama
        cout << endl;
        top++; // harus di tambah biar selanjut nya masuk ke array berikut nya
    }
    else
    {
        cout << "Stack Penuh" << endl;
        system("pause");
    }
}

void pop()
{
    if (!isEmpty())
    {
        cout << " Data mahasiswa yang dihapus adalah: " << endl;
        cout << " (NIM: " << value[top - 1].nim << " Nama: " << value[top - 1].nama << ") " << endl; // change this to value[top - 1].nim and value[top - 1].nama
        top--;
    }
    else
    {
        cout << "Data tidak tersedia !" << endl;
        system("pause");
    }
}

void tampil(int n)
{
    mahasiswa *data = new mahasiswa[n];
    int temp, i = 0;
    string temp2;

    if (isEmpty())
    {
        cout << " Stack is empty" << endl;
        return;
    }
    else
    {
        // Create a copy of the stack
        mahasiswa *copy = new mahasiswa[n];
        for (int j = 0; j < n; j++)
        {
            copy[j] = value[j];
        }

        // Copy elements from the "stack" to the array
        while (i < n)
        {
            data[i] = copy[top - 1 - i]; // top of the stack is the end of the array
            i++;
        }

        cout << " Stack sebelum diurutkan berdasarkan NIM adalah: " << endl;
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
        cout << " Stack setelah diurutkan berdasarkan NIM adalah: " << endl;
        for (int k = 0; k < i; k++)
        {
            cout << " " << (k + 1) << ". (NIM: " << data[k].nim;
            cout << " Nama: " << data[k].nama << ") " << endl;
        }
    }

    delete[] data;
}

int main()
{
    welcome();
    int n, menu;
    bool loop = true;

    cout << "\n\n ================================================" << endl;
    cout << " Masukkan jumlah mahasiswa yang ingin diinput : ";
    cin >> n;
    value = new mahasiswa[n];
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
        cout << " 1. Push" << endl; // Memasukkan data ke antrian
        cout << " 2. Pop" << endl;  // Menghapus top dari data antrian
        cout << " 3. Exit" << endl; // Keluar dari program
        cout << " Silahkan masukkan menu: ";
        cin >> menu;
        cout << endl;
        switch (menu)
        {
        case 1:
            system("cls");
            push(n);
            break;
        case 2:
            system("cls");
            pop();
            break;
        case 3:
            cout << endl;
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