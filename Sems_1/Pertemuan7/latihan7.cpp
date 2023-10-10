#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float pembagian(int x, int y)
{
    float hasilbagi;
    hasilbagi = (float)x / (float)y;
    return hasilbagi;
}

void menu_1()
{
    float x, y, hasil;
    cout << "masukkan nilai x :";
    cin >> x;
    cout << "masukkan nilai y :";
    cin >> y;
    hasil = x / y;
    cout << "hasil pembagian adalah: " << hasil;
}

float diskriminan(int a, int b, int c)
{
    double hasil;
    hasil = sqrt((b * b) - (4 * a * c));
    if (diskriminan > 0)
    {
        hasil = sqrt((b * b) - (4 * a * c));
    }
    else
    {
        hasil = 0;
    }
    return hasil;
}

void menu_2()
{
    float a, b, c, hasil;
    cout << "masukkan nilai a :";
    cin >> a;
    cout << "masukkan nilai b :";
    cin >> b;
    cout << "masukkan nilai c :";
    cin >> c;
    hasil = sqrt((b * b) - (4 * a * c));
    cout << "akar diskriminan adalah " << hasil;
}

void bubblesort(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void menu_3()
{
    int panjangarray;
    cout << "masukkan panjang array: ";
    cin >> panjangarray;
    int datablmterurut[panjangarray];
    for (int i = 0; i < panjangarray; i++)
    {
        cout << "data ke-" << i + 1 << " : ";
        cin >> datablmterurut[i];
    }
    bubblesort(datablmterurut, panjangarray);
    cout << "angka setelah diurutkan: " << endl;
    for (int i = 0; i < panjangarray; i++)
    {
        cout << "data ke-" << i + 1 << " : " << datablmterurut[i] << endl;
    }
}

void bubblesorts(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
void menu_4()
{
    int panjangarray;
    cout << "masukkan panjang array: ";
    cin >> panjangarray;
    int datablmterurut[panjangarray];
    for (int i = 0; i < panjangarray; i++)
    {
        cout << "data ke-" << i + 1 << " : ";
        cin >> datablmterurut[i];
    }
    bubblesorts(datablmterurut, panjangarray);
    cout << "angka setelah diurutkan: " << endl;
    for (int i = 0; i < panjangarray; i++)
    {
        cout << "data ke-" << i + 1 << " : " << datablmterurut[i] << endl;
    }
}

void bubblesortarray(string array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void menu_5()
{
    int n;
    cout << "masukkan jumlah huruf: ";
    cin >> n;
    string huruf[n];
    for (int i = 0; i < n; i++)
    {
        cout << "masukkan huruf ke-" << i + 1 << " : ";
        cin >> huruf[i];
    }
    bubblesortarray(huruf, n);
    cout << "huruf setelah diurutkan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "huruf ke-" << i + 1 << " : " << huruf[i] << endl;
    }
}

int main()
{
    int menu;
    string lanjut;
    do
    {
        cout << "1. pembagian\n";
        cout << "2. diskriminan\n";
        cout << "3. bubblesort\n";
        cout << "4. bubblesort terbalik\n";
        cout << "5. bubblesort huruf\n";
        cout << "6. keluar\n";
        cout << "masukkan pilihan: ";
        cin >> menu;

        if (menu == 1)
        {
            menu_1();
        }
        else if (menu == 2)
        {
            menu_2();
        }
        else if (menu == 3)
        {
            menu_3();
        }
        else if (menu == 4)
        {
            menu_4();
        }
        else if (menu == 5)
        {
            menu_5();
        }
        else if (menu == 6)
        {
            break;
        }
        cout << "\nlanjut Y/N: ";
        cin >> lanjut;
    } while (lanjut == "y" || lanjut == "Y");
}