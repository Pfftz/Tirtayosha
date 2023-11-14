#include <iostream>
#include <string>

using namespace std;

#define MAX 5
string jawir[MAX];
int top = 0;

bool isEmpty()
{
    return top == 0;
}

bool isFull()
{
    return top >= MAX;
}

void view()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        cout << "Antrian: ";
        for (int i = 0; i < top; i++)
        {
            cout << jawir[i] << " ";
        }
        cout << endl;
    }
}

void enqueue()
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        cout << "Masukkan data: ";
        cin >> jawir[top];
        top++;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < top - 1; i++)
        {
            jawir[i] = jawir[i + 1];
        }
        top--;
    }
}

int main()
{
    int menu;
    while (true)
    {
        view();
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid option" << endl;
        }
    }
}