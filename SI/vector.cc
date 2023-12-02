#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 8, 6, 0};

    auto f = [&v]() mutable
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    };

    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    auto urut = [&v]()
    {
        std::sort(v.begin(), v.end());
    };

    auto terbalik = [&v]()
    {
        std::reverse(v.begin(), v.end());
    };

    f();
    urut();
    f();
    terbalik();
    f();

    return 0;
}