//similar to leetcode 3229 even simpler than that
//convert the initial array [0,0,0,0] to target array
//only addition operations and no subtraction operations


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        long long result = 0;
        
        int curr = 0;
        int prev = 0;
        //isme sign change ka kuch mamla hai hi nahi
        for(int i = 0; i<n; i++){
            curr = target[i];
            if(abs(curr) > abs(prev)){
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};