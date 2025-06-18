//just a brute force approach
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int counter = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(i!=j && nums[i]==nums[j]){
                    counter++;
                }
            }
                if(counter == 0){
                    return nums[i];
                }
            }
        
        return -1;
    }
};

//now optimize

