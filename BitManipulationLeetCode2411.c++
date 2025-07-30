//TC : O(n)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> setBitIndex(32, -1); 

        for(int i = n-1; i>= 0; i--){
            //nums[i] ka binary representation banao 32 bits tak ka
            int endIndex = i;
            for(int j = 0; j<32; j++){
                if(!(nums[i] & (1<<j))){ //if jth bit is not set
                    if(setBitIndex[j] != -1){
                        endIndex = max(endIndex, setBitIndex[j]); //kis index tak mujhe jaana padega ki mera bit set ho jaaye
                    }
                }
                else{ //else matlb jth bit set hai already
                    setBitIndex[j] = i; //jth bit ith index ke saath set ho sakta hai
                }
            }
            result[i] = endIndex - i + 1;
        }
        return result;
    }
};
//right to left traverse karna hai
//each index ka setbit nikal na hai
//bit set karne ka matlb hai ki kis index par uske bit ke saath or karne se 1 mil raha hai, jis index ke saath or karne se 1 mil raha hai wo set hai
//dry run in my DSA copy youtube : code story with MIK