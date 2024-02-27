#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    std::ifstream file("D:\\Alprot\\Sems_2\\Pertemuan1\\databases.txt");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::istringstream iss(content);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word)
    {
        words.push_back(word);
    }

    std::map<std::string, int> dictionary;
    for (const auto &word : words)
    {
        dictionary[word] = std::rand() % 100 + 1; // generate random number between 1 and 100
    }

    // Print the dictionary
    for (const auto &pair : dictionary)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}