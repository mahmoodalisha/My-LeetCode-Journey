class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2;i<=n;i++){
            string current = "";
            int count = 1;
            for(int j = 1; j<result.length(); ++j){ //this is only to iterate within result
            if(result[j] == result[j-1]){
            count++;
            }
            else{
            current += to_string(count) + result [j-1];
            count = 1;
             }
        }
            current += to_string(count) + result[result.length()-1];
            result = current;
        }
        return result;
    }
};

/* Processing "21":
Iteration 1 (First Character - '2'):
count = 1: We see only one 2 at the beginning of the string.
current = '2': The character we're currently looking at is 2.
result = "": The result string is empty right now.
Since there's only one 2, we append "12" to result (the format is "count followed by the character")

Iteration 2 (Second Character - '1'):
count = 1: Now, we see one 1 after 2.
current = '1': Now the character we're processing is 1.
result = "12": We append "11" to the result because there is one 1 (again, "count followed by character").

result = "1211" now, because we added "one 1".
*/