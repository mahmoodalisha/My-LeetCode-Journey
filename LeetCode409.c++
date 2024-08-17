//Longest Pallindrome
//Leetcode Question 409

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> charCount;
    
    // Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    int length = 0;
    bool oddCountFound = false;

    // Calculate the length of the longest palindrome
    for (const auto& entry : charCount) {
        if (entry.second % 2 == 0) {
            length += entry.second; // Use all characters if the count is even
        } else {
            length += entry.second - 1; // Use the largest even number of characters
            oddCountFound = true;
        }
    }

    // Add one more character if there's any character with an odd count
    if (oddCountFound) {
        length++;
    }

    return length;
    }
};
