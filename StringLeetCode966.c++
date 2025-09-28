class Solution {
public:
    unordered_set<string> exactWords;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    string toLower(const string& s){
        string res = s;
        for(char& c : res){
            c = tolower(c);
        }
        return res;
    }
    string maskVowels(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }
string checkForMatch(const string& query) {
        // Exact match
        if (exactWords.count(query)) {
            return query;
        }

        // Case error match
        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        // Vowel error match
        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        // 4. No match
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(string word : wordlist){ //exactwords set me daalo
            exactWords.insert(word);

            string lowerWord = toLower(word); //ab usko lowercase banake map me daalo caseMap me daalo
            if(caseMap.find(lowerWord) == caseMap.end()){
                caseMap[lowerWord] = word;
            }

            string maskedWord = maskVowels(lowerWord);
            if(vowelMap.find(maskedWord) == vowelMap.end()){
                vowelMap[maskedWord] = word;
            }
        }
        vector <string> result;
        for(string query : queries){
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};
//dry run in my algo copy youtube : code story with mik