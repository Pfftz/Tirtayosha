#include <iostream>

using namespace std;

void point1()
{
    int a = 5;
    int b = 10;
    int *pA = &a;
    int *pB = &b;

    *pA = 20;
    *pB = 30;

    int &c = a;
    c = 40;
    a = 50;

    cout << "Nilai a: " << a << endl;
    cout << "Nilai pA: " << pA << endl;
    // cout << "Nilai b: " << b << endl;
    // cout << "Nilai pB: " << pB << endl;
    cout << "Nilai c: " << c << endl;
    cout << "Nilai &c: " << &c << endl;
}

void fungsiPtr(int *nilaiPtr){
    cout << "Nilai dari fungsiPtr: " << *nilaiPtr << endl;
    cout << "Alamat dari fungsiPtr: " << nilaiPtr << endl;
}

int main()
{
    point1();
    cout << endl;
    int x = 10;
    int *ptrX = &x; 
    fungsiPtr(ptrX); 
    return 0;
}