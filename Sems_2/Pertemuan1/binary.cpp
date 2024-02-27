#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int binary_search(vector<pair<string, string>> data_list, string x)
{
    int l = 0, r = data_list.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (data_list[m].first == x)
            return m;
        if (data_list[m].first < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    ifstream names_file("D:\\Alprot\\Sems_2\\Pertemuan1\\new_databases.txt");
    ifstream values_file("D:\\Alprot\\Sems_2\\Pertemuan1\\new_numbers.txt");

    vector<string> names;
    vector<string> values;
    string line;

    while (getline(names_file, line))
    {
        names.push_back(line);
    }

    while (getline(values_file, line))
    {
        values.push_back(line);
    }

    vector<pair<string, string>> data_nilai;
    for (int i = 0; i < names.size(); i++)
    {
        data_nilai.push_back(make_pair(names[i], values[i]));
    }

    sort(data_nilai.begin(), data_nilai.end());


    cout << "Pertemuan 1 - Binary Search in cpp" << endl;
    string x;
    cout << "Cari data = ";
    cin >> x;

    auto start_time = high_resolution_clock::now();

    int hasil = binary_search(data_nilai, x);

    auto end_time = high_resolution_clock::now();
    auto waktu = duration_cast<nanoseconds>(end_time - start_time).count();

    if (hasil != -1)
    {
        cout << "Elemen '" << x << "' ditemukan pada index " << hasil << " dengan nilai " << data_nilai[hasil].second << endl;
        cout << "Waktu yang dibutuhkan: " << waktu << " nanoseconds" << endl;
    }
    else
    {
        cout << "Elemen '" << x << "' tidak ada dalam array" << endl;
    }

    return 0;
}