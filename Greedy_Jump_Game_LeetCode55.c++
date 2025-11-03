/*
💡 Example 1 — Successful case
nums = [2,3,1,1,4]
| i | nums[i] | i + nums[i] | maxReach | i > maxReach? |
| - | ------- | ----------- | -------- | ------------- |
| 0 | 2       | 2           | 2        | ❌ No          |
| 1 | 3       | 4           | 4        | ❌ No          |
| 2 | 1       | 3           | 4        | ❌ No          |
| 3 | 1       | 4           | 4        | ❌ No          |
| 4 | 4       | 8           | 8        | ❌ No          |

💥 Example 2 — Failing case
nums = [3,2,1,0,4]
| i | nums[i] | i + nums[i] | maxReach | i > maxReach? |
| - | ------- | ----------- | -------- | ------------- |
| 0 | 3       | 3           | 3        | ❌ No          |
| 1 | 2       | 3           | 3        | ❌ No          |
| 2 | 1       | 3           | 3        | ❌ No          |
| 3 | 0       | 3           | 3        | ❌ No          |
| 4 | 4       | 8           | 3        | ✅ Yes!        |

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i>maxReach) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return true;
    }
};