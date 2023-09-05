#include <iostream>

using namespace std;

int main()
{
    //luas segitiga
    int p, l;
    float luas;

    cout << "panjang = ";
    cin >> p;
    cout << "lebar = ";
    cin >> l;

    luas = 0.5 * p * l;

    cout << "\n luas = " << luas << endl;

    return 0;
}