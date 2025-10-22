//difference Array technique
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxElement = *max_element(begin(nums), end(nums))+k; //sabse bada element nikal lo

        vector<int> freq(maxElement+1, 0);
        for(int &num : nums){
            freq[num]++;
        }
        //cumulative sum of frequency nikal lo
        for(int i = 1; i<= maxElement; i++){
             freq[i] += freq[i-1]; //add karte chale jaao
        }
        int result = 0; //max frequency jiska hoga usi ko result me store karenge
        for(int target = 0; target<= maxElement; target++){
            if(freq[target] == 0)
                continue;
            int leftNum = max(0, target-k); //max is an edge case
            int rightNum = min(maxElement, target+k); //min is an edge case

            int totalCount = freq[rightNum]-(leftNum-1>0 ? freq[leftNum-1] : 0);
            int targetCount = freq[target]-(target>0 ? freq[target-1] : 0);
            int needConversion = totalCount-targetCount;
            int maxPossibleFreq = targetCount+min(needConversion,numOperations);
            result = max(result, maxPossibleFreq);
        }
            return result;
    }
};

//youtube : code story with MIK