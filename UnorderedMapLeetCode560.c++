//brute force approach the sub array will be within i to j

//now the optimal one
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0; //presum is the key which is till the ith index
        int count = 0;   //count increases whenever we get k after presum - k

        for (int i = 0; i<nums.size();i++){
            presum += nums[i];
            int remove = presum - k;
            count += mpp[remove];   //addition in the count
            mpp[presum] += 1;
        }
        return count;
    }
};

/* 
unordered_map<int, int> mpp;
So mpp[3] = 5 means: "store value 5 with key 3"
Think of it like a dictionary:
mpp = {
  3: 5,
  7: 2,
  10: 8
  count += mpp[remove];
  
}
*/