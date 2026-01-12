class Solution {
public:
    typedef long long ll;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    ll sum = 0;
    int count = 0; //kitne nodes ko ab tak xor kia
    int minloss = INT_MAX;

    for(ll num : nums){
        if((num ^ k) > num){ //kya XOR karne pe wo bada value de raha hai ?
            count++; //one more number XORed
            sum += (num^k); //ab add kardo saare numbers ko
        }
        else{
            sum += num; //nahi to phir normal numbers ko add kardo
        }
        minloss = min((long long)minloss, abs(num - (num^k)));
    }
    if(count %2 == 0){ //matlab even number of nodes me XOR lagaya hai
        return sum; //tab yahi mera sum hoga
    }
    return sum - minloss; //sum karne ke baad jo minimum nuksaan hai usko minus karke return karo
    }
}; 

//youtube codestoryMIK