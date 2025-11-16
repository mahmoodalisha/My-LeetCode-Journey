/*
Let’s dry-run it 👇
Input: [0, 1, 0, 3, 12]

| i | nums[i] | nums[j++]    | Array after step  |
| - | ------- | ------------ | ----------------- |
| 0 | 0       | skip         | [0, 1, 0, 3, 12]  |
| 1 | 1       | nums[0] = 1  | [1, 1, 0, 3, 12]  |
| 2 | 0       | skip         | [1, 1, 0, 3, 12]  |
| 3 | 3       | nums[1] = 3  | [1, 3, 0, 3, 12]  |
| 4 | 12      | nums[2] = 12 | [1, 3, 12, 3, 12] |

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        while(j<nums.size()){
            nums[j++] = 0;
        }
    }
};