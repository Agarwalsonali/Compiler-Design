// Count total occurrence of each character in a given file (taking file from user)
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename, ios::binary); // open in binary mode to include all characters
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    map<char, int> charCount;
    char ch;

    while (file.get(ch)) {
        charCount[ch]++;
    }

    file.close();

    cout << "\nCharacter occurrences:\n";
    for (auto &entry : charCount) {
        if (entry.first == '\n')
            cout << "\\n"
                 << " -> " << entry.second << endl;
        else if (entry.first == '\t')
            cout << "\\t"
                 << " -> " << entry.second << endl;
        else if (entry.first == ' ')
            cout << "' ' (space)"
                 << " -> " << entry.second << endl;
        else
            cout << entry.first << " -> " << entry.second << endl;
    }

    return 0;
}
