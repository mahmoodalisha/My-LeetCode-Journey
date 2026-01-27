//Stack

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> mystack;
        

        for(char c : s){
            if(!mystack.empty() && mystack.top() == c){
                mystack.pop();
            } else{
                mystack.push(c);
            }    
        }

        string result = "";

        while(!mystack.empty()){
            result += mystack.top();
            mystack.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};