//difference array technique
//target ke each element ko nums ke each element se subtract karke difference array nikal lo
//ultimately diff array ko [0,0,0,0] bana do nums = target ho jayega
//diff array me two pointer lagao aur check karte chale jao kitna sub array bana sakte ho

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long result = 0;
        vector<int> diff(n);

        for(int i = 0; i<n; i++){
            diff[i] = target[i] - nums[i];
        }
        int curr = 0;
        int prev = 0;

        for(int i = 0; i<diff.size(); i++){
            curr = diff[i];
            //kahi sign change toh nahi hua ?
            if((curr > 0 && prev < 0) || (curr<0 && prev >0)){
                result += abs(curr);
            } else if(abs(curr) > abs(prev)){
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};
//youtube : code story with MIK