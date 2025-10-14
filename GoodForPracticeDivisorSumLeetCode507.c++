/*
Naively, you could do:
for (int i = 1; i < num; i++) {
    if (num % i == 0) { ... }
}
…but that’s very slow for large numbers (O(n) time).
So we optimize it by using a simple mathematical observation 👇

🔸 Key idea: Divisors come in pairs

Whenever i divides num,
then (num / i) is also a divisor.

Example:
Let’s take num = 28
| i | num / i | Pair    |
| - | ------- | ------- |
| 1 | 28      | (1, 28) |
| 2 | 14      | (2, 14) |
| 4 | 7       | (4, 7)  |

*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;

        int sum = 1;
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                sum += i;
                if(i != num/i) //add the pair divisor
                sum += num/i;
            }
        }
        if (sum == num) {
        return true;
        } else {
        return false;
        }
    }
};

/*
Next Part : we’re trying to find divisor pairs like this:
if i divides num, then num / i is also a divisor.
Example:
If num = 28 and i = 2,
then num / i = 14
→ both 2 and 14 are divisors.
*/