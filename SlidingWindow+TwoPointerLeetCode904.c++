//same question LC 159
//Just find the longest contiguous subarray that contains at most 2 distinct numbers


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int result = 0;
        unordered_map<int, int> freq;

        for(int right = 0; right<n; right++){
            freq[fruits[right]]++;
            while(freq.size() > 2){
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};