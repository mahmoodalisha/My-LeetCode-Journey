//sliding window:- j ko aage badhate chale jaao aur elements set me daalte chale jaao,
// phir window(i se j tak) ke andar agar element mil gaya jo 1 se zyada se usko set se nikaal do
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> myset;
        int i = 0, j = 0;
        int sum = 0, result = 0;

        while(j<nums.size()){
            if(!myset.count(nums[j])){
                sum += nums[j];
                result = max(result, sum);
                myset.insert(nums[j]);
                j++;
            } else{ //we have seen this nums[j] so time to shrink the windiow
                while(i<nums.size() && myset.count(nums[j])){
                    sum -= nums[i];
                    myset.erase(nums[i]);
                    i++; //window ko shrink kar do
                }
            }
        }
        return result;
    }
};