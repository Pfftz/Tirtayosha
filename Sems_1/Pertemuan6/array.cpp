#include <iostream>

using namespace std;

void arr1()
{
    int data[5];
    data[0] = 10;
    data[1] = 2;
    data[2] = 3;
    data[3] = 0;
    data[4] = 2;

    cout << data[4] << endl;
}

void arr2()
{
    char data[5];
    data[0] = 'a';
    data[1] = 'b';
    data[2] = 'c';
    data[3] = 'd';
    data[4] = 'e';

    cout << data[4] << endl;
}

void arr3()
{
    string data[5];
    data[0] = "data 1";
    data[1] = "data 2";
    data[2] = "data 3";
    data[3] = "data 4";
    data[4] = "data 5";

    cout << data[4] << endl;
}

void arr4()
{
    string data[5] = {"data 1", "data 2", "data 3", "data 4", "data 5"};

    cout << data[0] << endl;
}

void arr5()
{
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i] = rand() % 10; // 0 - 9
        cout << data[i] << " ";
    }
}

void arr6()
{
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        if (data[i] % 2 == 0)
        {
            cout << data[i] << " ";
        }
        else
        {
            cout << data[i] << " ";
        }
    }
}

void arr7()
{
    int n;
    cout << "Masukkan jumlah data : ";
    cin >> n;

    int data[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Data Ke-" << i + 1 << ": " << data[i] << endl;
    }
}

int main()
{
    arr1();
    cout << endl;
    cout << endl;
    arr2();
    cout << endl;
    cout << endl;
    arr3();
    cout << endl;
    cout << endl;
    arr4();
    cout << endl;
    cout << endl;
    arr5();
    cout << endl;
    cout << endl;
    arr6();
    cout << endl;
    cout << endl;
    arr7();

    return 0;
}