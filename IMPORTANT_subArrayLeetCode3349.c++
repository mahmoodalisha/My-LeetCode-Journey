class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 1; //to track the length of current sub array
        int prev = 0; //

        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){ //increasing hai
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }
            if(curr>=2*k){ //we can accomodate two subarrays in it length. >= k
                return true;
            }
            if(min(curr, prev)>=k){
                return true;
            }
        }
        return false;
    }
};
//youtube : code story with mik