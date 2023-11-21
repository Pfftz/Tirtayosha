#include <iostream>
#include <stdlib.h>
using namespace std;

#define max 5
string datok[max];
int top = 0;

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

bool isFull()
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

void display()
{
    if (!isEmpty())
    {
        cout << "Data Tersimpan : " << endl;
        for (int a = 0; a < top; a++)
        {
            cout << a + 1 << ". " << datok[a] << endl;
        }
    }
    else
    {
        cout << "Data tidak tersedia !" << endl;
    }
    if (isFull())
    {
        cout << "Stack Penuh" << endl;
    }
    cout << endl;
}

void push()
{
    if (!isFull())
    {
        cout << "Masukkan Data : ";
        cin >> datok[top];
        top++; // harus di tambah biar selanjut nya masuk ke array berikut nya
    }
}

void pop()
{
    if (!isEmpty())
    {
        top--;
    }
}

int main()
{
    int pilihan;
    string isi;
stack:
    system("cls");
    display();
    cout << "Menu Utama" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "Silahkan pilih Menu: ";
    cin >> pilihan;
    if (pilihan == 1)
    {
        // cout << "Tambah data / push" << endl;
        system("cls");
        push();
        goto stack;
    }
    else if (pilihan == 2)
    {
        // cout << "Keluarkan data / pop" << endl;
        //  hapus data terakhir
        pop();
        goto stack;
    }
    system("cls");
    return 0;
}