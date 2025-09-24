class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans;
        if((numerator<0) ^ (denominator<0)) ans+= "-"; //to take care of nagative inputs

        long long n = llabs(numerator);
        long long d = llabs(denominator);

        ans += to_string(n/d);
        long long remainder = n%d;
        if(remainder == 0) return ans; //no fraction left
        ans += "."; //now add the decimal

        unordered_map<long long, int> seen;
        while(remainder != 0){
            if(seen.find(remainder) != seen.end()){
                ans.insert(seen[remainder], "(");
                ans += ")";
                return ans;
            }
            seen[remainder] = ans.size();
            remainder *= 10;
            ans += to_string(remainder / d);
            remainder %= d;
        }
        return ans;
    }
};


/* we need XOR to take care of any negative numbers in the input
Use of XOR: It’s the simplest way to check if exactly one of two things is true.
If we skip it, negative fractions would wrongly come out positive in the final string.

| numerator < 0 | denominator < 0 | XOR result | Meaning                    |
| ------------- | --------------- | ---------- | -------------------------- |
| false         | false           | false      | both positive → no `-`     |
| true          | false           | true       | different signs → need `-` |
| false         | true            | true       | different signs → need `-` |
| true          | true            | false      | both negative → no `-`     |

*/
//The quotient (n / d) gives you the next digit.
//The remainder (n % d) tells you what’s left over and whether division is finished.
//If division is exact (remainder = 0 → stop).
//Or if it continues forever (remainder repeats → repeating cycle).