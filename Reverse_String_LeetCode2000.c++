class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index  = -1;
        for(int i = 0; i<word.size(); i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        int start = 0;
        int end = index;
        while(start<end){
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;

            start++;
            end--;
        }

        return word;
    }
};