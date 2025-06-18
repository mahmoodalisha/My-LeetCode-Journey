class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector <int> ans;
        for (int i = 0; i< nums.size(); i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
}; 

/* 
nums = [0, 2, 1, 5, 3, 4] hai:

Index (i)	nums[i]
0	          0
1	          2
2	          1
3	          5
4	          3
5	          4


i = 1 ➝ index 1
nums[i] = nums[1] = 2 ➝ value at index 1 is 2
nums[nums[i]] = nums[2] = 1
 */