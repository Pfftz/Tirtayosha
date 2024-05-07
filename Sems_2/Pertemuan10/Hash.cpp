#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <cstdlib> // Untuk sistem clear screen

using namespace std;

class HashTable {
private:
    int size;
    vector<vector<pair<int, unordered_map<string, string>>>> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    void insert(int key, string name, string job, int age, string sex, string eyes, string hair, string status) {
        int hashKey = hash(key);
        for (auto &kv : table[hashKey]) {
            if (kv.first == key) {
                kv.second = {{"name", name}, {"job", job}, {"age", to_string(age)}, {"sex", sex},
                             {"eyes", eyes}, {"hair", hair}, {"status", status}};
                return;
            }
        }
        table[hashKey].push_back({key, {{"name", name}, {"job", job}, {"age", to_string(age)}, {"sex", sex},
                                        {"eyes", eyes}, {"hair", hair}, {"status", status}}});
    }

    unordered_map<string, string> find(int key) {
        int hashKey = hash(key);
        for (auto &kv : table[hashKey]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return {};
    }

    void remove(int key) {
        int hashKey = hash(key);
        for (auto it = table[hashKey].begin(); it != table[hashKey].end(); ++it) {
            if ((*it).first == key) {
                table[hashKey].erase(it);
                return;
            }
        }
        throw out_of_range("Key not found");
    }

    // Function to print a formatted table
    void printTable() {
        cout << "================================================================================================================" << endl;
        cout << left << setw(10) << "Key" << setw(25) << "Name" << setw(20) << "Job" << setw(10) << "Age" << setw(10) << "Sex"
             << setw(15) << "Eye Color" << setw(15) << "Hair Color" << setw(10) << "Status" << endl;
        cout << "================================================================================================================" << endl;
        for (const auto &bucket : table) {
            for (const auto &kv : bucket) {
                cout << left << setw(10) << kv.first
                     << setw(25) << kv.second.at("name")
                     << setw(20) << kv.second.at("job")
                     << setw(10) << kv.second.at("age")
                     << setw(10) << kv.second.at("sex")
                     << setw(15) << kv.second.at("eyes")
                     << setw(15) << kv.second.at("hair")
                     << setw(10) << kv.second.at("status") << endl;
            }
        }
        cout << "================================================================================================================" << endl;
    }
};

void clearScreen() {
    // Clear screen for Windows, Linux, and macOS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printMenu() {
    cout << "========================= DWELLERS DATA MENU =========================" << endl;
    cout << "====================================================================" << endl;
    cout << "1. Insert\n2. Find\n3. Delete\n4. Print Table\n5. Quit" << endl;
    cout << "====================================================================" << endl;
    cout << "Choose an option: ";
}

void insertRecord(HashTable& vault) {
    int key, age;
    string name, job, sex, eyes, hair, status;
    cout << "Enter a key: ";
    cin >> key;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a job: ";
    cin >> job;
    cout << "Enter an age: ";
    cin >> age;
    cout << "Enter a sex: ";
    cin >> sex;
    cout << "Enter an eye color: ";
    cin >> eyes;
    cout << "Enter a hair color: ";
    cin >> hair;
    cout << "Enter a status (alive/dead): ";
    cin >> status;
    vault.insert(key, name, job, age, sex, eyes, hair, status);
}

void findRecord(HashTable& vault) {
    int key;
    cout << "Enter a key: ";
    cin >> key;
    auto data = vault.find(key);
    if (!data.empty()) {
        cout << "==============================================================================================================================================" << endl;
        cout << left << setw(10) << "Key" << setw(25) << "Name" << setw(20) << "Job" << setw(10) << "Age" << setw(10) << "Sex"
             << setw(15) << "Eye Color" << setw(15) << "Hair Color" << setw(10) << "Status" << endl;
        cout << "==============================================================================================================================================" << endl;
        cout << left << setw(10) << key
             << setw(25) << data.at("name")
             << setw(20) << data.at("job")
             << setw(10) << data.at("age")
             << setw(10) << data.at("sex")
             << setw(15) << data.at("eyes")
             << setw(15) << data.at("hair")
             << setw(10) << data.at("status") << endl;
        cout << endl << endl;
    } else {
        cout << "Key not found." << endl;
    }
}

void deleteRecord(HashTable& vault) {
    int key;
    cout << "Enter a key: ";
    cin >> key;
    try {
        vault.remove(key);
        cout << "Record with key " << key << " has been removed." << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}

int main() {
    HashTable vault(200);
    while (true) {
        clearScreen();
        printMenu();
        int option;
        cin >> option;
        switch (option) {
            case 1:
                insertRecord(vault);
                break;
            case 2:
                findRecord(vault);
                break;
            case 3:
                deleteRecord(vault);
                break;
            case 4:
                vault.printTable();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option, please try again." << endl;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        clearScreen();
    }
    return 0;
}
