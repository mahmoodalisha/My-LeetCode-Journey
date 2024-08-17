//check permutation in a string
//this is brute force approach
//sliding window is a better approach but i dont understand anything
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int len1 = s1.size();
        int len2 = s2.size();
        
        if (len1 > len2) {
            return false; // s1 cannot fit into s2
        }
        
        // Frequency arrays for characters 'a' to 'z'
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        // Populate the frequency array for s1
        for (char c : s1) {
            count1[c - 'a']++;
        }
        
        // Initialize the frequency array for the first window in s2
        for (int i = 0; i < len1; ++i) {
            count2[s2[i] - 'a']++;
        }
        
        // Check if the initial window matches
        if (count1 == count2) {
            return true;
        }
        
        // Slide the window over s2
        for (int i = len1; i < len2; ++i) {
            count2[s2[i] - 'a']++; // Add the new character to the window
            count2[s2[i - len1] - 'a']--; // Remove the old character from the window
            
            // Check if the current window matches
            if (count1 == count2) {
                return true;
            }
        }
        
        return false;
    }  
    
};;