class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        for(int i = 0; i<nums.size(); i++){
            if(mini<nums[i]) mini = nums[i];
            if(maxi>nums[i]) maxi = nums[i];
        }
        return gcd(mini, maxi);
    }
};