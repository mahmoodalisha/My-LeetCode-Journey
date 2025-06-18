class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0]; //Current range ka first number
        int end = nums[0];  //Current range ka last number

        for(int i = 1; i<n; i++){
            if(nums[i] == end+1){ //Check karta hai ki kya consecutive hain 

            // Extend the current range
            end = nums[i];
        } else{
            if(start == end){
                result.push_back(to_string(start));
            }
            else{
                result.push_back(to_string(start) + "->" + to_string(end));
            }
            // Start new range
                start = end = nums[i];
        }
    }
        if(start == end){
                result.push_back(to_string(start));
            }
            else{
                result.push_back(to_string(start) + "->" + to_string(end));
            }
        return result;
    }
}; 


/*
Dry run :
Pehle start = 0, end = 0

Next: nums[1] = 1
🔁 Check: 1 == end+1 -> 0 + 1 ✅ → consecutive → end = 1

Next: nums[2] = 2
🔁 Check: 2 == end+1 -> 1 + 1 ✅ → consecutive → end = 2

Next: nums[3] = 4
🔁 Check: 4 == end+1 -> 2 + 1 ❌ → Not consecutive

🟢 Toh ab pehle range "0->2" complete ho gaya — usko result me daal denge.

*/