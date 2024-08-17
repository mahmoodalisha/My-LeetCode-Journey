#include <iostream>
#include <cstring>
using namespace std;

void reverse(char name[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        swap(name[s++], name[e--]);
    }
}

int main() {
    char name[100];
    cout << "Enter your name: ";
    cin >> name;

    int length = strlen(name); // Calculate the length of the input string
    reverse(name, length); // Call the reverse function with the correct parameters

    cout << "Reversed name: " << name << endl; // Output the reversed name

    return 0;
}
