#include <iostream>

using namespace std;

int main()
{
    //luas segitiga
    int t, a;
    float luas;

    cout << " alas = ";
    cin >> a;
    cout << " tinggi = ";
    cin >> t;

    luas = 0.5 * t * a;

    cout << "\n luas = " << luas << endl;

    return 0;
}