#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    z = x % y;
    cout << "\n HCF of " << x << " and " << y << " is: " << z << endl;

    return 0;
}
