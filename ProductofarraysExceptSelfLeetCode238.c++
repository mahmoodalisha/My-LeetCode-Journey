class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);   //initialize with the size aur usme jo elements honge wo saare 1 honge
        
        
        int prefix = 1; //Prefix = multiplication of everything BEFORE me.
        for(int i = 0; i<n; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }


        //So after the first loop, result[i] already contains:product of everything to the LEFT
        int postfix = 1; //Postfix = multiplication of everything AFTER me.
        for(int i = n-1; i>=0; i--){ 
            result[i] *= postfix; //we need LEFT × RIGHT
            postfix *= nums[i];
        }

        return result;
    }
};


//youtube: Abhishek sensei