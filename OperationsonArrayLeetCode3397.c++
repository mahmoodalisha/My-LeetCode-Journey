class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN;
        
        for(int i = 0; i<n; i++){
            int min = nums[i]-k;
            if(prev<min){
                prev = min; //kardo
                count++;
            } else if(prev<nums[i]+k){
                //nums[i]=prev+1;
                prev = prev+1;
                count++;
            }
        }
        return count;
    }
};
//nums[i]-k karo phir check karte chale jaao
//nums[i-1]>=nums[i]-k nhi hona chahiye, kyun ki hume unique elements chahiye, agar ho gaya toh nums[i-1]+1 karo
//isse tumhe unique elements milte chale jayenge
//youtube : codestory with MIK