// Count total number of keywords in a file (taking file from user)
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

bool isKeyword(const string& word) {
    static const set<string> keywords = {
        "alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool",
        "break","case","catch","char","char16_t","char32_t","class","compl","const",
        "constexpr","const_cast","continue","decltype","default","delete","do",
        "double","dynamic_cast","else","enum","explicit","export","extern","false",
        "float","for","friend","goto","if","inline","int","long","mutable","namespace",
        "new","noexcept","not","not_eq","nullptr","operator","or","or_eq","private",
        "protected","public","register","reinterpret_cast","return","short","signed",
        "sizeof","static","static_assert","static_cast","struct","switch","template",
        "this","thread_local","throw","true","try","typedef","typeid","typename",
        "union","unsigned","using","virtual","void","volatile","wchar_t","while",
        "xor","xor_eq"
    };

    return keywords.find(word) != keywords.end();
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string word;
    int keywordCount = 0;

    while (file >> word) {
        if (isKeyword(word))
            keywordCount++;
    }

    file.close();

    cout << "Total number of C++ keywords in file: " << keywordCount << endl;

    return 0;
}
