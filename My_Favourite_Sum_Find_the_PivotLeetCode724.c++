class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0;
        int total = 0;
        
        for(int c : nums){
            total += c;
        }

        for(int i = 0; i<n; i++){
            int rightsum = total - leftsum -nums[i];
            if(leftsum == rightsum)
                return i; //found the pivot index
                leftsum += nums[i]; //move the boundary
        }
        return -1;
    }
};