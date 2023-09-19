#include <iostream>
using namespace std;

void ulang1()
{
    // 1
    for (int i = 1; i <= 100; i++)
    {
        cout << "index ke-" << i << " kelas B" << endl;
    }
}
void ulang2()
{
    // 2
    for (int x = 100; x >= 0; x--)
    {
        cout << "Index ke-" << x << endl;
    }
}

void ulang3()
{
    for (int a = 0; a < 10; a++)
    {
        if (a > 5)
        {
            cout << "data yang lebih besar dari 5: " << a << endl;
        }
    }
}
void ulang4()
{
    int i = 10;
    while (i > 0)
    {
        if(i>5){
            cout << "data yang lebih besar dari 5: " << i << endl;
        }
        // cout << " Data ke: " << i << endl;
        i--;
    }
}
void ulang5()
{
    int b = 5;
    do{
        cout << "Data ke: " << b << endl;
        b++;
    }
    while (b > 10);
}
void ulang6()
{
}
void ulang7()
{
}

int main()
{
    // ulang1();
    // ulang2();
    // ulang3();
    // ulang4();
    // ulang5();
    ulang6();
    return 0;
}