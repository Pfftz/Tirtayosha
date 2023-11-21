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

void welcome()
{
    string opening = R"(
          _____                _____                    _____                    _____                    _____          
         /\    \              /\    \                  /\    \                  /\    \                  /\    \         
        /::\    \            /::\    \                /::\    \                /::\    \                /::\____\        
       /::::\    \           \:::\    \              /::::\    \              /::::\    \              /:::/    /        
      /::::::\    \           \:::\    \            /::::::\    \            /::::::\    \            /:::/    /         
     /:::/\:::\    \           \:::\    \          /:::/\:::\    \          /:::/\:::\    \          /:::/    /          
    /:::/__\:::\    \           \:::\    \        /:::/__\:::\    \        /:::/  \:::\    \        /:::/____/           
    \:::\   \:::\    \          /::::\    \      /::::\   \:::\    \      /:::/    \:::\    \      /::::\    \           
  ___\:::\   \:::\    \        /::::::\    \    /::::::\   \:::\    \    /:::/    / \:::\    \    /::::::\____\________  
 /\   \:::\   \:::\    \      /:::/\:::\    \  /:::/\:::\   \:::\    \  /:::/    /   \:::\    \  /:::/\:::::::::::\    \ 
/::\   \:::\   \:::\____\    /:::/  \:::\____\/:::/  \:::\   \:::\____\/:::/____/     \:::\____\/:::/  |:::::::::::\____\
\:::\   \:::\   \::/    /   /:::/    \::/    /\::/    \:::\  /:::/    /\:::\    \      \::/    /\::/   |::|~~~|~~~~~     
 \:::\   \:::\   \/____/   /:::/    / \/____/  \/____/ \:::\/:::/    /  \:::\    \      \/____/  \/____|::|   |          
  \:::\   \:::\    \      /:::/    /                    \::::::/    /    \:::\    \                    |::|   |          
   \:::\   \:::\____\    /:::/    /                      \::::/    /      \:::\    \                   |::|   |          
    \:::\  /:::/    /    \::/    /                       /:::/    /        \:::\    \                  |::|   |          
     \:::\/:::/    /      \/____/                       /:::/    /          \:::\    \                 |::|   |          
      \::::::/    /                                    /:::/    /            \:::\    \                |::|   |          
       \::::/    /                                    /:::/    /              \:::\____\               \::|   |          
        \::/    /                                     \::/    /                \::/    /                \:|   |          
         \/____/                                       \/____/                  \/____/                  \|___|          
                                                                                                                         
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

bool isFull(int max)
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

void push(mahasiswa value[], int n)
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
        cout << "\n\n +----------------------------------------------+" << endl;
        cout << "                   Stack Penuh" << endl;
        cout << " +----------------------------------------------+" << endl;
        system("pause");
    }
}

void pop()
{
    if (!isEmpty())
    {
        top--;
    }
    else
    {
        cout << "Data tidak tersedia !" << endl;
        system("pause");
    }
}

void tampil(mahasiswa value[])
{
    if (isEmpty())
    {
        cout << " Stack is empty" << endl;
        return;
    }
    else
    {
        cout << " Stack sebelum diurutkan berdasarkan NIM adalah: " << endl;
        for (int k = top - 1; k >= 0; k--)
        {
            cout << " " << (k + 1) << ". (NIM: " << value[k].nim;
            cout << " Nama: " << value[k].nama << ") " << endl;
        }
        cout << endl;

        // Sort the array
        mahasiswa *sorted = new mahasiswa[top];
        for (int i = 0; i < top; i++)
        {
            sorted[i] = value[i];
        }
        for (int i = 0; i < top; i++)
        {
            for (int j = i + 1; j < top; j++)
            {
                if (sorted[i].nim > sorted[j].nim)
                {
                    mahasiswa temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = temp;
                }
            }
        }

        // Print the sorted elements
        cout << " Stack setelah diurutkan berdasarkan NIM adalah: " << endl;
        for (int k = top - 1; k >= 0; k--)
        {
            cout << " " << (top - k) << ". (NIM: " << sorted[k].nim;
            cout << " Nama: " << sorted[k].nama << ") " << endl;
        }
        delete[] sorted;
    }
}

int main()
{
    welcome();
    int n, menu;
    bool loop = true;

    cout << "\n\n ================================================" << endl;
    cout << " Masukkan jumlah mahasiswa yang ingin diinput : ";
    cin >> n;
    mahasiswa value[n];
    cout << " ================================================" << endl;
    cout << endl;
    system("pause");
    while (loop)
    {
        system("cls");
        SetConsoleTextAttribute(h, 9);
        cout << " +----------------------------------------------+" << endl;
        tampil(value);
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
            push(value, n);
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