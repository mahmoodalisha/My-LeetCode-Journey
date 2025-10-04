//just like linked list cycle detection

class Solution {
public:

    int sumSquare(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit*digit;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumSquare(n);
        while(fast != 1 && slow != fast){
            slow = sumSquare(slow); //move 1 step
            fast = sumSquare(sumSquare(fast)); //move 2 steps
        }
        return fast == 1; // 1 means happy number, else cycle
    }
};


//Socho har number n ek “node” hai, aur sumSquare(n) uska “next node” hai. Matlab:
//n → sumSquare(n) → sumSquare(sumSquare(n)) → ...
/*
Slow aur Fast pointer ka kaam
Hum do pointers use karte hain:
slow: ek step chalta hai har iteration me
fast: do steps chalta hai har iteration me
*/
/*
Logic:

Agar koi cycle (loop) hai → fast aur slow ek hi number pe mil jayenge (cycle detected → false).
Agar koi cycle nahi hai → fast pointer 1 pe pahunch jaayega (happy number → true).

Agar number cycle me fas gaya ho...

...to dono pointer ek din same number pe mil jaayenge,
kyunki dono same loop ke andar move kar rahe hain —
ek slow aur ek fast speed me.
*/