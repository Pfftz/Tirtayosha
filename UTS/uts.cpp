#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

float rumus1(float a, float b)
{
    float hasil;

    hasil = sqrt(pow(a, 2) + pow(b, 2));

    return hasil;
}

float rumus2(float a, float b, float c)
{
    float hasil;

    hasil = pow(b, 2) - (4 * a * c);

    return sqrt(hasil);
}

void menu1()
{
    float a, b, c;
    cout << " Masukkan nilai a: ";
    cin >> a;
    cout << " Masukkan nilai b: ";
    cin >> b;
    cout << " Masukkan nilai c: ";
    cin >> c;
    if (rumus2(a, b, c) > 0)
    {
        cout << " Nilai diskriminan adalah " << rumus2(a, b, c) << endl;
    }
    else
    {
        cout << " Nilai diskriminan tidak boleh negatif" << endl;
    }
    cout << endl;
    rumus1(a, b);
}

void menu4()
{
    int length;
    cout << " Masukkan panjang array: ";
    cin >> length;

    int databelumurut[length];
    for (int i = 0; i < length; i++)
    {
        cout << " Data ke-" << i + 1 << " : ";
        cin >> databelumurut[i];
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (databelumurut[j] < databelumurut[j + 1])
            {
                int temp = databelumurut[j];
                databelumurut[j] = databelumurut[j + 1];
                databelumurut[j + 1] = temp;
            }
        }
    }
    cout << "\n Angka setelah diurutkan: ";
    for (int i = 0; i < length; i++)
    {
        cout << " " << databelumurut[i] << " ";
    }
    cout << endl;
}

void menu7()
{
    int split, length;
    cout << " Masukkan panjang array: ";
    cin >> length;
    cout << " Masukkan split: ";
    cin >> split;

    int arr1[length];
    for (int i = 0; i < length; i++)
    {
        cout << " Data ke-" << i + 1 << " : ";
        cin >> arr1[i];
    }

    int arr2[length - split];
    for (int i = split; i < length; i++)
    {
        arr2[i - split] = arr1[i];
    }

    cout << "\n Array 1: ";
    for (int i = 0; i < split; i++)
    {
        cout << arr1[i] << " ";
    }

    for (int i = 0; i < split; i++)
    {
        for (int j = 0; j < split - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    cout << "\n Array 1 terurut: ";
    for (int i = 0; i < split; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n Array 2: ";
    for (int i = 0; i < length - split; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < split; i++)
    {
        for (int j = 0; j < split - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
}