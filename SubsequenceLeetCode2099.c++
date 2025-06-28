class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n){
            return nums;
        }
        vector<int>temp(nums);
        nth_element(begin(temp), begin(temp)+ k-1, end(temp), greater<int>()); //kthlargest element mil jaaye partial sorting
        int kthLargest = temp[k-1];
        int countKthLargest = count(begin(temp), begin(temp)+k, kthLargest);//kthLargest element kitni baar aaya hai
        vector<int> result;

        for(int num : nums){
            if(num > kthLargest){ //agar kthlargest se bada hai toh
                result.push_back(num);
            } else if(num == kthLargest && countKthLargest>0){
                result.push_back(num);
                countKthLargest--;
            }
            if(result.size() == k){
                break;
            }
        }
        return result;
    }
};