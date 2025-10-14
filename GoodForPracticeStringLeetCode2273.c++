/*
🔍 What sortedWord stores at each step

| Original Word | `sortedWord` (after `sort()`) |
| ------------- | ----------------------------- |
| `"abba"`      | `"aabb"`                      |
| `"baba"`      | `"aabb"`                      |
| `"bbaa"`      | `"aabb"`                      |
| `"cd"`        | `"cd"`                        |
| `"cd"`        | `"cd"`                        |

*/

/*
| Word   | Sorted | prev   | Action |
| ------ | ------ | ------ | ------ |
| "abba" | "aabb" | ""     | Add    |
| "baba" | "aabb" | "aabb" | Skip   |
| "bbaa" | "aabb" | "aabb" | Skip   |
| "cd"   | "cd"   | "aabb" | Add    |
| "cd"   | "cd"   | "cd"   | Skip   |

*/

class Solution {
public:
        vector<string> removeAnagrams(vector<string>& words){
            vector<string> result;
            string prev = "";
            
            for(auto& word : words){
                string sortedWord = word;
                sort(sortedWord.begin(), sortedWord.end());

                if(sortedWord != prev){
                    result.push_back(word); // keep only if it's not an anagram of previous
                    prev = sortedWord; // update previous sorted pattern
                }
            }
            return result;
    }
}