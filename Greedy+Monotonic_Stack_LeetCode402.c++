class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> mystack;

        for(char c : num){
            while(!mystack.empty() && k>0 && mystack.top()>c){
                mystack.pop();
                k--;
            }
            mystack.push(c);
        }
        //for the test case where num = "9" and k = 1
        while(k>0 && !mystack.empty()){
            mystack.pop();
            k--;
        }
        string result = "";
        while(!mystack.empty()){
            result += mystack.top();
            mystack.pop();
        }
        reverse(result.begin(), result.end());

        //remove leading zeroes
        int i = 0;
        while(i<result.size() && result[i] == '0') i++;
        result = result.substr(i);
        return result.empty() ? "0" : result;
    }
};