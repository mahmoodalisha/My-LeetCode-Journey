class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp; //keep updating temp with greater no.s in this way you will get the longest subsequence

        for(int num : nums){
        int left = 0;
        int right = temp.size()-1;
        int idx = temp.size();
        while(left<=right){
            int mid = left+(right-left)/2;

            if(temp[mid]>=num){
                idx=mid;
                right = mid-1; //search in the left half
            }
            else left =  mid+1; //search right
        }
        if(idx == temp.size()){
            temp.push_back(num);
        }
        else {
            temp[idx] = num; //replace with the bigger value
        }
    }
        return temp.size();
    }
};