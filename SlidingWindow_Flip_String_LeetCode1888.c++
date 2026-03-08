//Minimum Number of Flips to Make Binary String Alternating


class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //khandani sliding window
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j<2*n){
            char expectedCharS1;
            if(j%2){
                expectedCharS1 = '1';
            } else{
                expectedCharS1 = '0';
            }

            char expectedCharS2;
            if(j%2){
                expectedCharS2 =  '0';
            } else{
                expectedCharS2 = '1';
            }

            if(s[j%n] != expectedCharS1){
                flip1++;
            }

            if(s[j%n] != expectedCharS2){
                flip2++;
            }

            if(j-i+1 > n) { //shrink the window from left
                if (i % 2) {
                expectedCharS1 = '1';
            } else {
                expectedCharS1 = '0';
            }

            if (i % 2) {
                expectedCharS2 = '0';
            } else {
                expectedCharS2 = '1';
            }

                if(s[i%n] != expectedCharS1) {
                    flip1--;
                }

                if(s[i%n] != expectedCharS2) {
                    flip2--;
                }

                i++;
            }

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }

            j++;

        }
        return result;
    }
};