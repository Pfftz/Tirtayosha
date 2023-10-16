#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x1, x2, y1, y2;
    float jarak;
    cout << "Masukkan nilai x1 : ";
    cin >> x1;
    cout << "Masukkan nilai x2 : ";
    cin >> x2;
    cout << "Masukkan nilai y1 : ";
    cin >> y1;
    cout << "Masukkan nilai y2 : ";
    cin >> y2;
    jarak = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    cout << "Jarak antara titik (" << x1 << "," << y1 << ") dan (" << x2 << "," << y2 << ") adalah " << jarak << endl;
    return 0;
}