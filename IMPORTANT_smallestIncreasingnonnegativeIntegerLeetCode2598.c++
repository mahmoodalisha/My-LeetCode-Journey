//saare elements ka val se Modulo nikaalte chale jaao aur un saare modulo ko map me store karte chale jaao, map me wo saare elements ka modulo rahega aur unki frequency
//phir start MEX = 0 matlab MEX ko zero see start karo aur check karte chale jaao ki map me hai ki nahi, map me hai toh frequency ghate chale jaao
//if set doesn't contain MEX wahi result hai

//TC O(n)
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mpp;

        for(int &num : nums){
        int r = ((num%value)+value)%value;
        mpp[r]++;
        }

        int MEX = 0;
        while(mpp[(MEX%value)]>0){
            mpp[(MEX)%value]--;
            MEX++;
        }
        return MEX;
    }
};