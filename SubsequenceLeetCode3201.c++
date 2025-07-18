
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int countEven = 0; //length of even numbers of subsequence;
        int countOdd = 0; //length of odd numbers of subsequence
        for(int &num : nums){
            if(num%2==0){ //even parity
            countEven++;
            }
            else {
                countOdd++;
            }
        }
        int parity = nums[0]%2;
        int alternating = 1; //length of the alternating parity no. subsequence
        for(int i = 1; i<n; i++){
            int currParity = nums[i]%2;
            if(currParity != parity){ //then its alternating parity
                alternating++;
                parity = currParity;
            }
        }
        return max({countEven, countOdd, alternating});
    }
};
/* Bas condition hai: sab ka sum ek hi parity ka ho — ya sab even ho ya sab odd ho aur Har consecutive pair ka sum equal ho.
Even + Even = Even 
Odd + Odd = Even 
Odd + Even = Odd 
Even + Odd = Odd 

dry run in my DSA copy
youtube : code story with MIK
*/