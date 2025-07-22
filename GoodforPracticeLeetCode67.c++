//Add two binary numbers thats it
class Solution {
public:
    string addBinary(string a, string b) {
        string result = 0;
        int carry = 0;

        int i = a.size()-1;
        int j = b.size()-1;

        while( i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sim += b[j--] - '0';

            result += (sum%2) + '0';
            carry = sum/2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
