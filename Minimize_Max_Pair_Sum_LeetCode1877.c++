/* Two Pointer Approach

Pairs dhundo aur add karo
But direct Max Sum nahi maanga hai question me
Saare pairs nikaalo
Phir un pairs me sabse chota pair jo hai uska max sum return karo

Example 1:

Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.

Is example me :- 
{(3,5), (2,3)}  => {(8), (5)}
{(3,3), (5,2)}  => {(6), (7)}

pairs ban rahe hai lekin hum 7 return karenge kyun ki wo minimized pair hai aur is pair ka max sum 7 hai
*/
//but intuition bas yahi hai ki max element ko min ke saath add kardo wahi answer hai

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int i = 0;
        int j = nums.size()-1;

        while(i<j){
            int sum = nums[i] + nums[j];
            result = max(result, sum);
            i++;
            j--;
        }
        return result;
    }
};


//Similar to LeetCode 881