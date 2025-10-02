class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int start = 0;

        for(int i = 0; i<=s.size(); i++){
            if(i == s.size() || s[i] == ' '){ 
                string oneword = s.substr(start, i-start);
                
                //now reverse the word by swapping
                int l = 0, r = oneword.size()-1;
                while(l<r){
                swap(oneword[l], oneword[r]);
                l++;
                r--;
            }

            if(result != "") result += " ";
            result += oneword;
            start = i+1;
            }
        }
        return result;
    }
};
/*
Input: "Hello World"

First iteration:
start = 0
i = 5 → s[5] = ' ' → current word = s.substr(0,5) = "Hello"

Reverse "Hello" → "olleH"

Ab next word ka start → start = i + 1 = 6

Next iteration:
i continue karega → i = 11 (string end)
Current word = s.substr(6, 11-6) = "World"
*/