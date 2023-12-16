#include <iostream>
#include <algorithm>

using namespace std;

void menghitungchardarikalimat(){
    std::string sentence;
    int jumlah[26] = {0}; // Array to store the count of each letter

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, sentence); // Read the full line of text, including spaces

    // Process each character in the string
    for (char ch : sentence)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            jumlah[ch - 'a']++; // Increment count for lowercase
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            jumlah[ch - 'A']++; // Increment count for uppercase, treating them as lowercase
        }
        // Non-alphabetic characters are ignored
    }

    // Display the counts
    for (int i = 0; i < 26; i++)
    {
        if (jumlah[i] > 0)
        {
            std::cout << (char)(i + 'a') << " = " << jumlah[i] << ", ";
        }
    }

    std::cout << std::endl;
}

void mencarichardarikalimat(){
    std::string sentence;
    char targetChar;
    int count = 0;

    // Get the sentence from the user
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, sentence);

    // Ask for the character to search for
    std::cout << "Masukkan karakter yang ingin dicari: ";
    std::cin >> targetChar;

    // Iterate through the sentence and count occurrences of targetChar
    for (char ch : sentence)
    {
        if (ch == targetChar)
        {
            count++;
        }
    }

    // Output the result
    std::cout << "Karakter '" << targetChar << "' muncul " << count << " kali dalam kalimat." << std::endl;
}

int main()
{
   
    menghitungchardarikalimat();
    cout << endl;
    mencarichardarikalimat();
    cout << endl;
    string sentence;
    cout << "Masukkan kalimat: ";
    cin.ignore();
    getline(cin, sentence);
    string hasil(sentence);
    cout << hasil << endl;
    reverse(hasil.begin(), hasil.end());
    cout << hasil << endl;

    return 0;
}