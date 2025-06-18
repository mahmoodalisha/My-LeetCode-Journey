//Leetcode 189

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k%n;
            vector <int> temp (k);
            //Copy last k elements to temp
            for(int i = 0;i<k;i++){
                temp[i] = nums[n - k + i];
            }
            //now shift remaining elements to the right
            for(int i = n-1; i>=k; i--){
                nums[i] = nums[i-k];
            }
            //Copy temp back to front
            for(int i = 0; i<k; i++){
                nums[i] = temp[i];
            }
        }
    };