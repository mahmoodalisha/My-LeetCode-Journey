/*
Given a string s and an integer k
reverse the first k characters for every 2k characters counting from the start of the string.
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i<n; i += 2 * k){
            int left = i;
            int right = min(i+k-1, n-1);

            while(left<right){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
        }
        return s;
    }
};