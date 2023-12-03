#include <iostream>
#include <tuple>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    tuple<int, int, int> t = {1, 3, 8};
    tuple<int, int, int> t2 = {2, 1, 2};

    auto f = [&t]()
    {
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    };

    auto urut = [&t]()
    {
        array<int, 3> a = {get<0>(t), get<1>(t), get<2>(t)};
        sort(a.begin(), a.end());
        t = make_tuple(a[0], a[1], a[2]);
    };

    auto terbalik = [&t]()
    {
        array<int, 3> a = {get<0>(t), get<1>(t), get<2>(t)};
        reverse(a.begin(), a.end());
        t = make_tuple(a[0], a[1], a[2]);
    };

    auto tambah = [&t, &t2]()
    { tuple<int, int, int, int, int, int> t3 = tuple_cat(t, t2); 
      cout << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3) << " " << get<3>(t3) << " " << get<4>(t3) << " " << get<5>(t3) << endl; };

    auto tukar = [&t, &t2]()
    {
        t.swap(t2);
    };

    f();
    urut();
    cout << endl;
    f();
    cout << endl;
    terbalik();
    f();
    cout << endl;
    tambah();
    cout << endl;
    tukar();
    f();

    return 0;
}