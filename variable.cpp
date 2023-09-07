#include <iostream>

using namespace std;

int main()
{
    float r, k, l;
    const float phi = 3.14;
    cout << "r = ";
    cin >> r;
    k = 2 * phi * r;
    l = phi * r * r;

    cout << "luas = " << l << "\nkeliling = " << k << endl;
    return 0;
}