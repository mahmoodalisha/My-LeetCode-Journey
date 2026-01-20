class Solution {
public:
    bool isVowel(char &c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            unordered_map<char, int> freq;
            for(int j = i; j<n; j++){
                if(!isVowel(word[j])){
                    break;
                }
                freq[word[j]]++;

                if(freq.size() == 5){
                    count++;
                }
            }
        }
        return count;
    }
};

/* 

Dry run
word = "aeiouu"

i = 0
j = 0 → a → {a}
j = 1 → e → {a,e}
j = 2 → i → {a,e,i}
j = 3 → o → {a,e,i,o}
j = 4 → u → {a,e,i,o,u} → count = 1
j = 5 → u → {a,e,i,o,u} → count = 2

i = 1
j = 1 → e → {e}
j = 2 → i → {e,i}
j = 3 → o → {e,i,o}
j = 4 → u → {e,i,o,u} ❌ missing a
j = 5 → u → still ❌


No new counts.
🔹 i = where substring STARTS
🔹 j = where substring ENDS
🔹 map = which vowels exist in THIS substring
🔹 map.size() == 5 → valid substring
🔹 new i → everything resets automatically
*/