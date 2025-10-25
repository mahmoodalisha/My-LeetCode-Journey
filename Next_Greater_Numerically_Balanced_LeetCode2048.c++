/*
An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
Given an integer n, return the smallest numerically balanced number strictly greater than n.

Example 1:

Input: n = 1
Output: 22
Explanation: 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.

Example 2:
Input: n = 1000
Output: 1333
Explanation: 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.

Example 3:
Input: n = 3000
Output: 3133
Explanation: 
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.
*/

class Solution {
public:
    bool balanced(int num){
        vector<int> freq(10); //size of the array is 10
        while(num>0){
            int digit = num%10;
            freq[digit]++;
            num /= 10;
        }
        for(int i = 0; i<10; i++){ //ab freq me iterate karo aur dekho ki balanced hai ya nahoi
        if(freq[i] != 0 && freq[i] != i) //isi line se balance check ho raha hai
        return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int num = n+1; num<=1224444; num++){
            if(balanced(num)){
                return num;
            }
        }
        return -1;
    }
};