class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i<n; i++){
            int num = abs(nums[i]);
            int idx = num-1; //dry run in my DSA copy
            if(nums[idx]<0){ //matlab visited hai
                result.push_back(num);
            }
            else{ //usko visited mark kar do
                nums[idx] *= -1;
            }
        }
        return result;
    }
};
