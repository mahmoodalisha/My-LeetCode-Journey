//palindome ka length 3 hona chahiye aur unique hona chahiye
//abcba me se aba banega aur bcb banega
//ek element uthao uska leftmost aur rightmost index dekho phir beech me kitne elements aa rahe hai dekhlo
//beech ke elements ko set me daal do
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> letters;

        for(char &ch : s){
            letters.insert(ch);
        }

        int result = 0;
        for(char letter : letters){

            //ek letter pakdo wo kitna left pe hai aur kitna right pe hai mark karo
            int leftmost = -1;
            int rightmost = -1;

            for(int i = 0; i<n; i++){
                if(s[i] == letter){
                    if(leftmost == -1){
                        leftmost = i;
                    }
                    rightmost = i;
                }
            }
            unordered_set<char>st;
            //beech me kaun kaun se elements aa rahe hai aur palindrome bana rahe hai
            for(int middle = leftmost+1; middle<=rightmost-1; middle++){
                st.insert(s[middle]);
            }
            result += st.size(); //matlab middle me kitne elements mil rahe, wahi saare milke palindrome bana rahe
        }
        return result;
    }
};