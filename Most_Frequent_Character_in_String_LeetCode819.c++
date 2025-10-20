class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq; //to store the frequency of the words  
        string word = "";

        //Normalize: make everything lowercase and replace punctuation with spaces
        for(char& c : paragraph){
            if(isalpha(c))
                c = tolower(c);
            else
                c = ' ';
        }
        stringstream ss(paragraph);
        while(ss>>word){
            if(bannedSet.find(word) == bannedSet.end()){ //not banned
            freq[word]++;
            }
        }
        //now return the word with the greatest frequency but not banned
        string mostCommon = "";
        int maxFreq = 0;
        for(auto& [w, count] : freq){
            if(count > maxFreq){
                maxFreq = count;
                mostCommon = w;
            }
        }
        
        return mostCommon;
    }
};
/*
paragraph = "the ball hit the wall"
banned = ["the"]

Then : bannedSet = {"the"}


| word   | bannedSet.find(word) == bannedSet.end()?     | Action             |
| ------ | ----------------------------------------     | ------------------ |
| "the"  | ❌ false (found in bannedSet)                | skip it            |
| "ball" | ✅ true (not banned)                         | freq["ball"]++ → 1 |
| "hit"  | ✅ true                                      | freq["hit"]++ → 1  |
| "the"  | ❌ false                                     | skip               |
| "wall" | ✅ true                                      | freq["wall"]++ → 1 |

👉 The unordered_map (let’s call it freq) is used to count the frequency of each word.
👉 But we only insert or update words that are not in the banned list.
 */

 /*
 What find() does bannedSet.find(word) searches for word inside the set
 it’s used to skip banned words

✅ Not found → safe to count → freq[word]++
❌ Found → skip it entirely
  */