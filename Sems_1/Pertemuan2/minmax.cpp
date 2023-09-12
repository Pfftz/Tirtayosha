#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // Minimum and maximum number of data type
    cout << " Bilangan Minimum char = " << CHAR_MIN << endl;
    cout << " Bilangan Maximum char = " << CHAR_MAX << endl;
    cout << " Ukuran Tipe char = " << sizeof(char) << endl;

    cout << "\n Bilangan Minimum unsigned char = " << numeric_limits<unsigned char>::min() << endl;
    cout << "\n Bilangan Maximum unsigned char = " << UCHAR_MAX << endl;
    cout << " Ukuran Tipe Uchar = " << sizeof(unsigned char) << endl;

    cout << "\n Bilangan Minimum short = " << SHRT_MIN << endl;
    cout << " Bilangan Maximum short = " << SHRT_MAX << endl;
    cout << " Ukuran Tipe short =" << sizeof(short) << endl;

    cout << "\n Bilangan Minimum unsigned short = " << numeric_limits<unsigned short>::min() << endl;
    cout << "\n Bilangan Maximum unsigned short = " << USHRT_MAX << endl;
    cout << " Ukuran Tipe Ushort =" << sizeof(unsigned short) << endl;

    cout << "\n Bilangan Minimum integer = " << INT_MIN << endl;
    cout << " Bilangan Maximum integer = " << INT_MAX << endl;
    cout << " Ukuran Tipe Integer = " << sizeof(int) << endl;

    cout << "\n Bilangan Minimum unsigned int = " << numeric_limits<unsigned int>::min() << endl;
    cout << "\n Bilangan Maximum unsigned int = " << UINT_MAX << endl;
    cout << " Ukuran Tipe Uint = " << sizeof(unsigned int) << endl;

    cout << "\n Bilangan Minimum long integer = " << LONG_MIN << endl;
    cout << " Bilangan Maximum long integer = " << LONG_MAX << endl;
    cout << " Ukuran Tipe long integer = " << sizeof(long) << endl;

    cout << "\n Bilangan Minimum unsigned long integer = " << ULONG_MAX << endl;
    cout << "\n Bilangan Maximum unsigned long integer = " << ULONG_MAX << endl;
    cout << " Ukuran Tipe Ulong integer = " << sizeof(unsigned long) << endl;

    cout << "\n Bilangan Minimum float = " << numeric_limits<float>::min() << endl;
    cout << " Bilangan Maximum float = " << numeric_limits<float>::max() << endl;
    cout << " Ukuran Tipe float = " << sizeof(float) << endl;

    cout << "\n Bilangan double = " << numeric_limits<double>::min() << endl;
    cout << " Bilangan double = " << numeric_limits<double>::max() << endl;
    cout << " Ukuran Tipe double = " << sizeof(double) << endl;

    return 0;
}