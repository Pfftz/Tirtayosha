#include <iostream>
#include <iomanip>

using namespace std;

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

union hexadesimal
{
    unsigned long desimal;
    float akhir;
};

int main()
{
    string n;
    hexadesimal bilangan;
    cout << "................\n";
    cout << "Inputkan hexadecimal:\n";
    cin >> n;
    stringstream keconvert(n);
    keconvert >> hex >> bilangan.desimal;
    float akhir = bilangan.akhir;
    cout << endl
         << "Data yang anda inputkan adalah: " << endl;
    cout << "Angka = " << akhir << endl;
    return 0;
}