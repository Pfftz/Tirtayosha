#include <iostream>
using namespace std;
int main()
{
    int a = 2;
    int b = 7;
    int c = 6;
    int y;
    y = a + b * c;
    cout << "\t<<Quiz>>\n\n";
    if (y == 25 || y == 26)
    {
        cout << "cukup sama baik" << endl;
    }
    else if (y >= 20 && y != 25 && y != 26)
    {
        cout << "sangat baik sekali" << endl;
    }
    else if (y < 20 && y != 25 && y != 26)
    {
        cout << "sangat baik" << endl;
    }
    cout << "\nPfftx\n";
    return 0;
}