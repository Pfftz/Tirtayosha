#include <iostream>
#include <math.h>

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

void menu2()
{
    int databelumurut[6] = {5, 3, 4, 2, 1, 5}, n = 6;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (databelumurut[j] > databelumurut[j + 1])
            {
                int temp = databelumurut[j];
                databelumurut[j] = databelumurut[j + 1];
                databelumurut[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << databelumurut[i] << " ";
    }
    cout << endl;
}

void menu3()
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
            if (databelumurut[j] > databelumurut[j + 1])
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

void menu5()
{
    int length;
    cout << " Masukkan panjang array: ";
    cin >> length;

    char databelumurut[length];
    for (int i = 0; i < length; i++)
    {
        cout << " Data ke-" << i + 1 << " : ";
        cin >> databelumurut[i];
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (databelumurut[j] > databelumurut[j + 1])
            {
                char temp = databelumurut[j];
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

void menu6()
{
    int length;
    cout << " Masukkan panjang array: ";
    cin >> length;

    char databelumurut[length];
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
                char temp = databelumurut[j];
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

    for (int i = 0; i < length - split; i++)
    {
        for (int j = 0; j < (length - split) - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    cout << "\n Array 2 terurut: ";
    for (int i = 0; i < length - split; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main()
{
    int pilihan;
    bool menu = true;

    while (menu)
    {
        cout << "\n Menu: " << endl;
        cout << " 1. Menghitung Phytagoras" << endl;
        cout << " 2. Bubble sort" << endl;
        cout << " 3. Bubble sorting dinamis" << endl;
        cout << " 4. Bubble sorting dinamis terbalik" << endl;
        cout << " 5. Bubble sorting dinamis Huruf" << endl;
        cout << " 6. Bubble sorting dinamis Huruf terbalik" << endl;
        cout << " 7. Split array" << endl;
        cout << " 8. Exit" << endl;
        cout << " Silahkan pilih menu: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
        case 1:
            menu1();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            menu2();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            menu3();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            menu4();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            // ascending
            menu5();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            // descending
            menu6();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            menu7();
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << " Menu tidak tersedia" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}