#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 6;
    int c = 7;
    int d = 8;

    auto f = [a, &b, &c, d]()
    {
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
    };

    a = 10;
    b = 11;
    c = 12;
    d = 13;

    f();
    
    return 0;
}