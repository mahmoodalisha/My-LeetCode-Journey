class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // st is the name of the stack
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {  // pushing these parenthesis at the top of the stack
                st.push(ch);
            } else {  // for closing brackets
                if (!st.empty()) {
                    if ((ch == ')' && st.top() == '(') ||
                        (ch == '}' && st.top() == '{') ||
                        (ch == ']' && st.top() == '[')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        } 
        return st.empty();
    }
};