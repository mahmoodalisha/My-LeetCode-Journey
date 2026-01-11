/*
In simple terms:-count karo nums me kitne elements ke sum ith queries se less than equal to hai
aur wo count apne array me push karke return kardo

Example 1:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> answer;
        for(int i : queries){
            int sum = 0;
            int count = 0;

            for(int j : nums){
                if(sum + j <= i){
                    sum += j;
                    count++;
                } else{
                    break;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};