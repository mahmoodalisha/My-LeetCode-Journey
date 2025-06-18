class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> myarray(nums.size());
        int i = 1;
        int j = nums.size()-1;

        while(i<nums.size()){
            myarray[i] = nums[j];
            i = i+2;
            j--;
        }
        i = 0; //reset the i
        while(i<nums.size()){
            myarray[i] = nums[j];
            i = i+2;
            j--;
        }
        for(int k = 0; k<nums.size(); k++){
            nums[k]=myarray[k];
        }
    }
};
//youtube: Aditya goyal
//check gallery screenshot for DRY RUN