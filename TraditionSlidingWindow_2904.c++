class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int left = 0;
        int count = 0;

        for(int right = 0; right<s.size(); right++){
            if(s[right] == '1'){
                count++;
            }
            while(count == k){
                string current = s.substr(left, right-left+1);
                if(ans == "" || current.length() < ans.length() || (current.length() == ans.length() && current < ans)){
                    ans = current;
                }
                if(s[left] == '1'){
                    count--;
                }
                left++;
            }
        }
        return ans;
    }
};