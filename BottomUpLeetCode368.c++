//this will not work this is recursion+memoization, you will have to optimize using bottom up approach
//youtube: code story with MIK
class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev){
        if(idx >= nums.size()) {
            if(temp.size()>result.size()){
                result = temp; //result updated rahega
            }
            return;
        }
        
        if(prev == -1 || nums[idx] % prev == 0){ //matlb prev se divisible hai, take karo
        temp.push_back(nums[idx]); //current element ko daal diya
        solve(idx+1, nums, result, temp, nums[idx]/*present idx*/);
        temp.pop_back(); //not take wala option
        }
        solve(idx+1, nums, result, temp, prev); //
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> result;
        vector<int> temp;//current element ko lete chale jaana

        int prev = -1; //temp abhi khaali hai matlab previous element nahi hai, prev matlb temp me jo last element tha
        solve(0, nums, result, temp, prev);
        return result;
    }
};


//bottom up approach same as that of leetcode 300
//bottom up approach, this approach follows leetcode 300
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> t(n,1); //dp array
        vector<int> prev_idx(n, -1);

        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 1; i< n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]%nums[j] == 0){
                    if(t[i] < t[j] + 1){
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }
                    if(t[i]>maxL){
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }
        vector<int> result;
        while(last_chosen_index != -1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }
        return result;
    }
};