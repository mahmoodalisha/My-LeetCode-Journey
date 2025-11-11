//apply operations on sub array to make it zero
//ultimately make the full array zero and return the minimum no. operations

//Approach (Optimal using Monotonic Increasing Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;

        int ops = 0;

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && st.top() > nums[i]) {
                st.pop();
            }

            if(nums[i] == 0)
                continue;
            
            if(st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
                ops++;
            }
        }

        return ops;
    }
};
//youtube : code story with MIK