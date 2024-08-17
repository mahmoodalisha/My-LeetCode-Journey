//Return the maximum occuring character in an input string
//using hashmap
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char maxOccurring(string s) {
    unordered_map<char, int> freqMap; // Map to store frequency of each character

    // Count the frequency of each character
    for (char ch : s) {
        freqMap[ch]++;
    }

    // Find the character with the maximum frequency
    char maxChar = s[0];
    int maxCount = 0;
    for (const auto& entry : freqMap) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            maxChar = entry.first;
        }
    }
    
    return maxChar;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "The maximum occurring character is: " << maxOccurring(s) << endl;
    return 0;
}


