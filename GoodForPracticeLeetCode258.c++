class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int sum = 0;
        while(num>0){ //Yahaan num > 0 ka matlab hai: jab tak number me digits bachi hain, loop chalti rahe. Jab number 0 ho jaata hai → sab digits process ho chuki hain → loop khatam.
            int last_digit = num%10;
            sum += last_digit;
            num /=10 ;
        }
        return addDigits(sum);
    }
};

/* 
Example (num = 38)

Iteration 1
num = 38 → num > 0 ✅ → loop chalta hai
lastDigit = 38 % 10 = 8
sum = 0 + 8 = 8
num /= 10 → num = 3

Iteration 2
num = 3 → num > 0 ✅ → loop chalta hai
lastDigit = 3 % 10 = 3
sum = 8 + 3 = 11
num /= 10 → num = 0

Iteration 3
num = 0 → num > 0 ❌ → loop khatam

*/