class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;
        int prevCount = 0; //keep the count of previous subarrays with odd elements and keep on adding
        int result = 0;

        int i = 0;
        int j = 0;

        while(j<n){
            if(nums[j]%2 != 0){ //matlab odd hai
                oddCount++;
                prevCount = 0;
            }
            while(oddCount == k){
                prevCount++;
                if(nums[i]%2 == 1){
                    oddCount--;
                }
                i++;
            }
            result += prevCount;
            j++;
        }
        return result;
    }
};

/*
example input: [2,1,2]
[2,1]
[1]
[1,2]
[2,1,2]
*/

//youtube: code story with MIK