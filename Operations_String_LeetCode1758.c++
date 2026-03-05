//minimum operations to make the full string alternating
//0101010101 is alternating

/*
Pattern A → 010101...
Pattern B → 101010...

So we check how many flips are needed for each pattern.
start0 = number of changes needed if the string starts with '0'
Example pattern:
index: 0 1 2 3
string:0 1 0 1

So expected characters are:
even index → 0
odd index  → 1


start1 = number of changes needed if the string starts with '1'
Example pattern:
index: 0 1 2 3
string:1 0 1 0

So expected characters are:
even index → 1
odd index  → 0

Final Answer-We take the minimum: min(start0, start1) = min(2,2) = 2
*/


class Solution {
public:
    int minOperations(string s) {
        int start0 = 0; // flips needed if pattern starts with '0' -> 010101
        int start1 = 0; // flips needed if pattern starts with '1' -> 101010

        for(int i = 0; i<s.length(); i++){
            // check pattern starting with 0
            if(i%2 == 0){ // even index should be '0'
                if(s[i] != '0'){ //if we are at an even index, the character should be '0' If it is not '0', then we must flip it, so we increase start0
                    start0++;
                }
            }
                else{ // odd index should be '1'
                    if(s[i] != '1'){
                        start0++;
                    }
                }

            // check pattern starting with 1
            if(i%2 == 0){
                if(s[i] != '1'){
                    start1++;
                }
            } else {
                if(s[i] != '0'){
                    start1++;
                }
            }
        }
        return min(start0, start1);
    }
};
