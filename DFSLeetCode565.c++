class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        for(int i = 0; i<n; i++){
            int start = nums[i];
            start = -1;
            int length = 0;

            while(start != -1){
                length++;
                int temp = start;
                start = nums[start];
                nums[temp] = -1;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};

//see the value of the index we are standing at and hop to the next index according to the value
//if we are standing at 0th index and the value at that index is 5, then hop to the 5th index

/*
start holds the index we're going to visit next

We need to mark the current element as visited, i.e., nums[temp] = -1

If you do nums[start] = -1 before assigning start = nums[start];, you'll lose the value you need
*/
//youtube: coding decoded