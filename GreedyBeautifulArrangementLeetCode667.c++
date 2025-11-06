/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/beautiful-arrangement-ii/
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int low = 1;
        int high = k+1;

        while(low<=high){
            result.push_back(low++);
                if(low<=high){
                    result.push_back(high--);
                }
        }
        for(int i = k+2; i<=n; i++){
            result.push_back(i);
        }
        return result;
    }
};

//code story with MIK
/*
🧮 Step-by-step dry run for n = 20, k = 10

Step 1️⃣: start with two pointers

low = 1
high = k + 1 = 11


Step 2️⃣: alternate low–high
Hum alternating pattern banate hain, jab tak low <= high
| i  | pick    | array                     |
| -- | ------- | ------------------------- |
| 1  | low=1   | [1]                       |
| 2  | high=11 | [1,11]                    |
| 3  | low=2   | [1,11,2]                  |
| 4  | high=10 | [1,11,2,10]               |
| 5  | low=3   | [1,11,2,10,3]             |
| 6  | high=9  | [1,11,2,10,3,9]           |
| 7  | low=4   | [1,11,2,10,3,9,4]         |
| 8  | high=8  | [1,11,2,10,3,9,4,8]       |
| 9  | low=5   | [1,11,2,10,3,9,4,8,5]     |
| 10 | high=7  | [1,11,2,10,3,9,4,8,5,7]   |
| 11 | low=6   | [1,11,2,10,3,9,4,8,5,7,6] |

Now, we’ve used numbers from 1 → 11.
Let’s check the differences:

|11-1|=10, |2-11|=9, |10-2|=8, |3-10|=7, |9-3|=6, |4-9|=5, |8-4|=4, |5-8|=3, |7-5|=2, |6-7|=1

➡️ Differences = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} ✅ (Exactly k = 10 distinct differences!)

Step 3️⃣: add the remaining numbers (11→20)
Actually, we already used up to 11, so we continue from 12 → 20:

Final array:

[1,11,2,10,3,9,4,8,5,7,6,12,13,14,15,16,17,18,19,20]
*/