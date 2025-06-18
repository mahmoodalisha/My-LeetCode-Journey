/*
Let’s say nums = [10, 9, 2, 5, 3, 7, 101, 18]

The temp vector evolves like:
10
9 → replaces 10: [9]
2 → replaces 9: [2]
5 → append: [2, 5]
3 → replaces 5: [2, 3]
7 → append: [2, 3, 7]
101 → append: [2, 3, 7, 101]
18 → replaces 101: [2, 3, 7, 18]
So LIS length = 4


What does idx represent?
idx is the index of the first element in temp that is greater than or equal to num

Suppose temp = [2, 3, 7, 18], and num = 5.
We do binary search to find the first element ≥ 5:
5 < 7 → found at index 2
So, idx = 2 — meaning we will replace temp[2] = 7 with num = 5.
Now temp becomes: [2, 3, 5, 18]
✅ This keeps the sequence valid and minimal at every length.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp; //keep updating temp with greater no.s in this way you will get the longest subsequence

        for(int num : nums){
        int left = 0;
        int right = temp.size()-1;
        int idx = temp.size();
        while(left<=right){
            int mid = left+(right-left)/2;

            if(temp[mid]>=num){
                idx=mid;
                right = mid-1; //search in the left half
            }
            else left =  mid+1; //search right
        }
        if(idx == temp.size()){
            temp.push_back(num);
        }
        else {
            temp[idx] = num; //replace with the bigger value
        }
    }
        return temp.size();
    }
};

//youtube: striver