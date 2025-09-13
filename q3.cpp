// Count total number of operators in a file (taking file from user)
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
using namespace std;

bool isOperator(const string& token) {
    static const set<string> operators = {
        // Arithmetic
        "+", "-", "*", "/", "%", "++", "--",
        // Assignment
        "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|=",
        // Relational
        "==", "!=", ">", "<", ">=", "<=",
        // Logical
        "&&", "||", "!",
        // Bitwise
        "&", "|", "^", "~", "<<", ">>",
        // Other
        "?", ":", "->", ".", ".*", "->*"
    };
    return operators.find(token) != operators.end();
}

// Function to remove comments from code
string removeComments(const string &code) {
    string result;
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for (size_t i = 0; i < code.size(); i++) {
        if (inSingleLineComment && code[i] == '\n') {
            inSingleLineComment = false;
            result += code[i];
        } else if (inMultiLineComment && code[i] == '*' && i + 1 < code.size() && code[i + 1] == '/') {
            inMultiLineComment = false;
            i++; 
        } else if (!inSingleLineComment && !inMultiLineComment) {
            if (code[i] == '/' && i + 1 < code.size() && code[i + 1] == '/') {
                inSingleLineComment = true;
                i++;
            } else if (code[i] == '/' && i + 1 < code.size() && code[i + 1] == '*') {
                inMultiLineComment = true;
                i++;
            } else {
                result += code[i];
            }
        }
    }
    return result;
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

    string line, content;
    while (getline(file, line)) {
        if (!line.empty() && line[0] == '#')
            continue;
        content += line + "\n";
    }
    file.close();

    content = removeComments(content);

    map<string, int> operatorCount;

    for (size_t i = 0; i < content.size(); i++) {
        string three = content.substr(i, 3);
        string two   = content.substr(i, 2);
        string one   = content.substr(i, 1);

        if (isOperator(three)) {
            operatorCount[three]++;
            i += 2;
        } else if (isOperator(two)) {
            operatorCount[two]++;
            i += 1;
        } else if (isOperator(one)) {
            operatorCount[one]++;
        }
    }

    int total = 0;
    cout << "\nOperators found:\n";
    for (auto &op : operatorCount) {
        cout << op.first << " -> " << op.second << "\n";
        total += op.second;
    }

    cout << "\nTotal number of operators: " << total << endl;
    return 0;
}
