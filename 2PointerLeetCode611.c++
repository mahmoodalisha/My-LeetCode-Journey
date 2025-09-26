//sum of any two sides > third side
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int k = nums.size()-1; k>=2; k--){
            int i = 0;
            int j = k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                count += (j - i);  // all between i..j-1 work nums[i] + nums[j] > nums[k], toh: nums[i+1] + nums[j] aur nums[i+2] + nums[j] … sab bhi > nums[k] honge. Matlab ek shot me (j - i) valid triangles mil gaye.
                j--;
                }
                else {
                    i++; //Agar condition false hai (nums[i] + nums[j] <= nums[k]) Matlab chhoti side (nums[i]) badhane ki zarurat hai, kyunki sum chhota hai. Isliye i++ karte hain → next bada number choose karte hain taaki inequality satisfy ho sake.
                }
            }
        }
        return count;
    }
};
/* 
Step 1: Sort the array. Jaise hi array sort hota hai, triangle condition a+b > c simplify ho jati hai.

Step 2: k kaha se start hoga?k largest side ko point karta hai.
Isliye k ko end se start karte hain (i.e., n-1)
Fir k ko 2 tak le jaate hain (kyunki triangle banane ke liye at least 3 elements chahiye).

Step 3: i aur j kaha se start honge?
For each fixed k:
i = 0 → array ki shuruaat se (smallest side)
j = k-1 → largest ke just pehle (second largest side)

*/