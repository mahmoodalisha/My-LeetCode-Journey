/*You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

Output: 7

Explanation:

First Transformation (t = 1):

'a' becomes 'b' as nums[0] == 1
'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'y' becomes 'z' as nums[24] == 1
'y' becomes 'z' as nums[24] == 1
String after the first transformation: "bcdzz"
Second Transformation (t = 2):

'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'd' becomes 'e' as nums[3] == 1
'z' becomes 'ab' as nums[25] == 2
'z' becomes 'ab' as nums[25] == 2
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.

*/
class Solution {
public:
    const int MOD = 1e9 + 7;

    using matrix = vector<vector<long long>>;

    matrix multiply(const matrix& A, const matrix& B) {
        int size = A.size();
        matrix result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {  //A[i][k] → A matrix ka i-th row, k-th column value hai
            for (int k = 0; k < size; k++) {   //B[k][j] → B matrix ka k-th row, j-th column value hai.
                for (int j = 0; j < size; j++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    matrix power(matrix base, int exponent) {
        int size = base.size();
        matrix result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) result[i][i] = 1; // identity matrix

        while (exponent > 0) {
            if (exponent % 2 == 1) result = multiply(result, base);
            base = multiply(base, base);
            exponent /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Step 1: Initial frequency vector
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Build transition matrix
        matrix trans(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int target = (i + j) % 26;
                trans[target][i] = (trans[target][i] + 1) % MOD;
            }
        }

        // Step 3: Raise matrix to power t
        trans = power(trans, t);

        // Step 4: Multiply final freq = trans * freq
        vector<long long> result(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                result[i] = (result[i] + trans[i][j] * freq[j]) % MOD;
            }
        }

        // Step 5: Total sum
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + result[i]) % MOD;
        }
        return total;
    }
};
