//greedy approach

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0; //to track each step we go deeper

        for(char c : s){
            if(c == '('){
            if(depth > 0) //so with this line of code we are actually skipping the first outer paraentheses as required in the question
                result += c;
                depth++;
            }
            else{
                depth--;
                if(depth > 0)
                    result += c;
            }
        }
        return result;
    }
}; 
//in this whole process of depth++ and depth -- and adding them to the result, we are just skipping and not adding those braces which are open 