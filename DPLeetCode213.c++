class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i>n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int steal = nums[i]+solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);
        return t[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){ //matlab agar ek hi ghar hai toh waha se chori karke nikal lo
            return nums[0]; //usi ghar se chori karo
        }

        if(n == 2){
            return max(nums[0], nums[1]); //dono ghar me se jis ghar me zyada paisa hai usse chori karo
        }
        memset(t, -1, sizeof(t));
        int rob_0th_house = solve(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        int rob_1st_house = solve(nums, 1, n-1);
        return max(rob_0th_house, rob_1st_house);
    }
};