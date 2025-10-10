//First is the Brute Force Approach with 2 loops that gives TLE
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result;

        for(int i = 0; i< n; i++){
            int count = 0; //count will reset after 1 full spells iteration 
            for(int j = 0; j < m; j++){
                long long product = (long long) spells[i]*potions[j];
                if(product >= success){
                    count++;
                }
            }
            result.push_back(count);
        } 
        return result;
    }
};

/*
Har spell ke liye:

count 0 se start hota hai
Sare potions ke saath multiply hota hai
Jitne products ≥ success hote hain, unka count hota hai
Fir us spell ka final count result vector me push hota hai
Next spell ke liye count fir se reset hota hai (0)
 */

//Now is the optimized approach that uses binary search
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        vector<int> result;
        sort(potions.begin(), potions.end());

        for(int spell : spells) {
            long long need = (success+spell-1)/spell;
            int left = 0;
            int right = m-1;
            int firstIndex = m;  // Default: agar koi potion >= need na mile
            while(left<=right){
                int mid = (left+right)/2;
                if(potions[mid]>=need){
                    firstIndex=mid;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            int count = m-firstIndex;
            result.push_back(count);
        }
        return result;
    }
};
/* 
Tumhe har spell ke liye batana hai:
Kitne potions aise hain jinke saath multiply karne par product ≥ success ho?

Hum spells array me iterate kar rahe hain ek-ek spell ke liye.

Binary search sirf potions array me laga rahe hain, taaki fast find ho jaaye kaunsa potion se product ≥ success start hota hai.

*/ 