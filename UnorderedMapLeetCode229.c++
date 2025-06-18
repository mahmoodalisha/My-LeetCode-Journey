class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int>mpp;
        int n = nums.size();

        for(int num : nums){
            mpp[num]++;
        }

        for(auto& pair: mpp){
            if(pair.second > n/3){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};