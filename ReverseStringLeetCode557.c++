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
/*
| i   | s[i] | start | Current word (s.substr(start, i-start)) | Action            |
| --- | ---- | ----- | --------------------------------------- | ----------------- |
| 0   | L    | 0     | -                                       | continue          |
| 1   | e    | 0     | -                                       | continue          |
| 2   | t    | 0     | -                                       | continue          |
| 3   | '    | 0     | -                                       | continue          |
| 4   | s    | 0     | -                                       | continue          |
| 5   | ' '  | 0     | "Let's"                                 | reverse → "s'teL" |
|     |      | 6     | (next word start)                       | update start      |
| 6   | t    | 6     | -                                       | continue          |
| 7   | a    | 6     | -                                       | continue          |
| 8   | k    | 6     | -                                       | continue          |
| 9   | e    | 6     | -                                       | continue          |
| 10  | ' '  | 6     | "take"                                  | reverse → "ekat"  |
|     |      | 11    | (next word start)                       | update start      |
| ... | ...  | ...   | ...                                     | ...               |


*/