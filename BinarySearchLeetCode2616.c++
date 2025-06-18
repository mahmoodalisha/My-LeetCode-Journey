class Solution {
public:
    //pehle pairs banao, check karo ki adjacent elements ka difference lessa than equal to mid kab tak jaa raha hai
    bool minpairs(int mid, vector<int>& nums, int p){
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]<=mid){
                p--; //aage badho dusre pairs banao jinko subtract karka mid se kam aa raha hai
                i++;
            }
        }
        if(p<=0) {return true;}
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        //now apply binary search
        int left = 0;
        int ans=INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            bool result = minpairs(mid, nums, p);  
            if(result){
                ans=mid;  
                right=mid-1; //aur bhi choti values ko explore karenge
            }
            else{
                left=mid+1; //nahi to phir badi values ko hi explore karenge
            }
        }
        return ans;
    }
};

//youtube: thinkcode