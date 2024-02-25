#include <iostream>

using namespace std;

// Function to calculate HCF using Euclidean Algorithm
int calculateHCF(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main()
{
    int x, y;

    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    int hcf = calculateHCF(x, y);

    cout << "HCF of " << x << " and " << y << " is: " << hcf << endl;

    return 0;
}
