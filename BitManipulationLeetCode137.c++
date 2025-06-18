class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<32;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += (nums[j] >> i) & 1;
            }
            sum %= 3;
            if(sum == 1) ans |= sum << i;
        }
        return ans;
    }
};

//Answer ke bits wahi honge jinke position par 1s ka count % 3 == 1 ho
//Yani un bits ko set karo in answer, kyunki wahi unique number se aaye hain!

/* 
Number	Binary	        0th Bit
2	    00000010	    0
2	    00000010	    0
3	    00000011	    1 ✅
2	    00000010	    0

*/