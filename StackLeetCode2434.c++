class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i<s.size(); i++){
            mpp[s[i]]++;
        }

        string result = "";
        stack<char> st;
        char min = 'a';

        for(int i = 0; i<s.size(); i++){
            st.push(s[i]);
            mpp[s[i]]--;
            while(min!='z' && mpp[min] == 0){
                min++; //stack ke andar minimum wala kaunsa hai  a->b->c->d
            } 
            while(!st.empty() && st.top()<=min){
                result.push_back(st.top());
                st.pop();
            }
        }
        return result;
    }
};

//youtube: eye on AI and DSA