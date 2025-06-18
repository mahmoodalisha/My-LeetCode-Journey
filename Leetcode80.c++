//Remove the 3rd dupliacate in the array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int  i = 2; //i is an index that starts with 2, as starting 2 elements will always be equal
        for (int j = 2; j<nums.size(); j++){
            //If nums[j] (the current element) is different from nums[i - 2], it means nums[j] is not the third occurrence of the same element, and it is safe to include it in the array.
            //When we look at nums[i - 2], we're checking the last occurrence of the element that can be at most twice in the array.
            if (nums[j]!=nums[i-2]){  //nums[i-2] is the last element of the two duplicate elements
                nums[i] = nums[j];  //updates the whole array
                i++;
            }
        }
        return i;
    }
};