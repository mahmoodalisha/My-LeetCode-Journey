//Replace spaces in a given string by @40
#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(const string& s) {
    string result;
    for (char ch : s) {
        if (ch == ' ') {
            result += "@40"; // Append "@40" for each space
        } else {
            result += ch; // Append the character as it is
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Read the entire line including spaces

    string output = replaceSpaces(input);
    cout << "Modified string: " << output << endl;

    return 0;
}
