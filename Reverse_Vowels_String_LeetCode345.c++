/*
What is k doing?
👉 k is walking through the original string s
Think of k as a finger moving left → right over the string.

Example:
s = "hello"
indexes: 0 1 2 3 4
chars:   h e l l o
          ↑
          k

So:
k = 0 → 'h'
k = 1 → 'e'
k = 2 → 'l'
...
k = 4 → 'o'

What is idx doing?
👉 idx is pointing to the vowel array
vowels = ['o', 'e']
indexes:  0    1
           ↑
          idx

So:
idx = 0 → first vowel
idx = 1 → second vowel
⚠️ idx only moves when we place a vowel

Why do we need TWO variables?
Variable	Moves over	Purpose
k	original string s	Find vowel positions
idx	vowel array	Pick next reversed vowel
Step-by-step Dry Run 🔍
After reversing vowels:
s      = "hello"
vowels = ['o', 'e']
idx = 0

k = 0
s[0] = 'h' → not a vowel
do nothing

k = 1
s[1] = 'e' → vowel ✅
s[1] = vowels[idx] = 'o'
idx++ → idx = 1

Now string is:
h o l l o
k = 2, 3
'l', 'l' → not vowels → skip

k = 4
s[4] = 'o' → vowel ✅
s[4] = vowels[idx] = 'e'
idx++ → idx = 2

Final string:
h o l l e
One-line intuition 🧠
k finds where to put vowels
idx tells which vowel to put next

*/

//First vowel swaps with last vowel
//Second vowel swaps with second-last vowel, and so on
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' ||  c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        vector<char> vowels;
        for(char c : s){
            if(isVowel(c)){
                vowels.push_back(c);
            }
        }
            //reverse vowels using temp
            int i = 0;
            int j = vowels.size()-1;
            while(i<j){
                char temp = vowels[i];
                vowels[i] = vowels[j];
                vowels[j] = temp;
                i++;
                j--;
            }
        
        //put vowels back into the string
        int idx = 0;
        for(int k = 0; k<s.size(); k++){
            if(isVowel(s[k])){
                s[k] = vowels[idx];
                idx++;
            }
        }
        return s;
    }
};