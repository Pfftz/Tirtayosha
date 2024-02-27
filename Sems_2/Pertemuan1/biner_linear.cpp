#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int simple_search(vector<pair<int, string>> data_list, int x)
{
    for (int i = 0; i < data_list.size(); i++)
    {
        if (data_list[i].first == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    srand(time(0));

    // Open the file
    ifstream file("D:\\Alprot\\Sems_2\\Pertemuan1\\databases.txt");
    vector<string> content;
    string word;

    // Read the content
    while (file >> word)
    {
        content.push_back(word);
    }

    // Close the file
    file.close();

    vector<pair<int, string>> data_nilai;

    // Generate random numbers and pair with content
    for (auto &word : content)
    {
        data_nilai.push_back(make_pair(rand() % 100 + 1, word));
    }

    // Print the data
    for (auto &data : data_nilai)
    {
        cout << "(" << data.first << ", " << data.second << ")" << endl;
    }

    int x;
    cout << "Cari data = ";
    cin >> x;

    auto start_time = high_resolution_clock::now();

    int hasil = simple_search(data_nilai, x);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    if (hasil != -1)
    {
        cout << "Elemen '" << x << "' ditemukan pada index " << hasil << " dengan nilai " << data_nilai[hasil].second << endl;
        cout << "Waktu yang dibutuhkan: " << duration.count() << " microseconds" << endl;
    }
    else
    {
        cout << "Elemen '" << x << "' tidak ada dalam array" << endl;
    }

    return 0;
}