//Stack
class Solution {
public:
    string process(string str){
        stack<char> st;
        for(char c : str){
            if(c == '#'){
                if(!st.empty()) st.pop();
            } else{
                st.push(c);
            } 
        }
        //build the string from the stack
        string result;
        result.reserve(st.size()); //avoid reallocation
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end()); // reverse once at end
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};