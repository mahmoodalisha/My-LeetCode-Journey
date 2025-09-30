class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;  // negative or 0 ugly nahi hote
        vector<int> primes = {2,3,5};
        for(int i = 0; i<primes.size(); i++){ //For loop → chal raha hai primes array ke 3 elements pe
            while(n%primes[i]==0){
                n /= primes[i];  // repeatedly divide by prime factor
            }
        }
        return n == 1;  // agar 1 bach gaya → ugly
    }
};
/*
Example: n = 24, primes[i] = 2
24 % 2 = 0 → n = 24/2 = 12
12 % 2 = 0 → n = 12/2 = 6
6 % 2 = 0 → n = 6/2 = 3
3 % 2 != 0 → loop khatam
Phir for loop next prime pe chala → primes[i] = 3
 */

 /* For a custom input 72
 Step 1: i = 0 → primes[0] = 2

n = 72, 72 % 2 == 0 → n = 72 / 2 = 36
n = 36, 36 % 2 == 0 → n = 36 / 2 = 18
n = 18, 18 % 2 == 0 → n = 18 / 2 = 9
n = 9, 9 % 2 != 0 → while loop khatam
After i=0 → n = 9

Step 2: i = 1 → primes[1] = 3
n = 9, 9 % 3 == 0 → n = 9 / 3 = 3
n = 3, 3 % 3 == 0 → n = 3 / 3 = 1
n = 1, 1 % 3 != 0 → while loop khatam

After i=1 → n = 1

Step 3: i = 2 → primes[2] = 5
n = 1, 1 % 5 != 0 → while loop khatam
After i=2 → n = 1
 
 return n == 1;  true Yes, 72 ka final n = 1 → ugly number ✅

 */