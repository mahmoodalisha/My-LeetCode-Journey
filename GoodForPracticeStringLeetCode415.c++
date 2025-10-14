class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string result = "";
        int carry = 0;

        while(i>=0 || j>=0 || carry){
            int x = (i>=0) ? num1[i]-'0' : 0; //coverting the character to integer using their ascii values
            int y = (j>=0) ? num2[j]-'0' : 0;

            int sum = x+y+carry;
            result += (sum%10)+'0';
            carry = sum/10;

            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};