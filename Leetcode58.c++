class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        //skip the space which if it is at the last of the sentence,The purpose of this check is to identify whether the current character in the string is a space. If it is a space, the loop will continue to decrement the index i to skip over any trailing spaces at the end of the string.
        //it means dont worry, move on
        while(i>=0 && s[i] == ' '){
            i--;
        }
        //count the last word, here s[i] !='' is the space before the last word
        while(i>=0 && s[i] != ' '){
            length++;
            i--;
        }
        return length;
    }   
    
};