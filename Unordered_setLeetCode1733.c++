class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set <int> sadUsers;

        for(auto &friends : friendships){
            int u = friends[0]-1;   //convert this to 0th index as friendships belong to languages which does not start from 0th index
            int v = friends[1]-1;
        unordered_set<int> langSet(begin(languages[u]), end(languages[u]));
        bool canTalk = false;
        for(int lang : languages[v]){
            if(langSet.count(lang)){
                canTalk = true;
                break;
            }
        }
            if(!canTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }
        vector<int> maxKnownLang(n+1, 0);
        int mostKnownLang = 0;

        for(int user : sadUsers) {
            for(int lang : languages[user]) {
                maxKnownLang[lang]++;
                mostKnownLang = max(mostKnownLang, maxKnownLang[lang]);
            }
        }
        return sadUsers.size()-mostKnownLang;
    }
};
//Dry Run in my DSA copy
//youtube : code story with MIK