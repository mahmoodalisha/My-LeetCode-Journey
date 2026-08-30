//possibility 1: delete from left side and right side
//possibility 2: delete both of them from the left side
//possibility 3: delete both of them from the right side

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0; //index(position) of the smallest element
        int maxIndex = 0; //index(position) of the largest element

        // Find positions of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Put smaller index in minIndex
        // and larger index in maxIndex
        if (minIndex > maxIndex)
            swap(minIndex, maxIndex);

        // 1. Both from front
        int front = maxIndex + 1;

        // 2. Both from back
        int back = n - minIndex;

        // 3. One from front, one from back
        int bothSides = (minIndex + 1) + (n - maxIndex);

        return min({front, back, bothSides});
    }
};