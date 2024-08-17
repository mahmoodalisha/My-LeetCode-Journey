//remove spaces in a string
#include <iostream>
using namespace std;

void removeSpaces(string &s) {
    int n = s.length();
    int j = 0;  // Pointer for the new string without spaces

    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];  // Copy non-space characters
        }
    }

    s.resize(j);  // Resize the string to the new length without spaces
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);  // Read input with spaces

    removeSpaces(s);  // Remove spaces from the string

    cout << "String after removing spaces: " << s << endl;

    return 0;
}
