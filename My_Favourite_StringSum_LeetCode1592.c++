/*
1592. Rearrange Spaces Between Words

You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.
Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
Return the string after rearranging the spaces.


Example 1:
Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.

Example 2:
Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
*/

class Solution {
public:
    string reorderSpaces(string text) {
        int countspaces = 0;
        for(char c : text){
            if(c == ' '){
                countspaces++;
            }
        }
        //Done counting no. of spaces, now extract words
        vector<string> words;
        stringstream ss(text);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        //if only one word all spaces go to the end
        if(words.size() == 1){
            return words[0] + string(countspaces, ' ');
        }
        int gaps = words.size()-1;
        int spacebetween = countspaces/gaps;
        int extraspaces = countspaces%gaps;

        string result = "";
        string gap(spacebetween, ' ');// create a string of N spaces matlab saare spaces ghusaao evenly distributed spaces
        for(int i = 0; i<words.size(); i++){
            result += words[i]; //ab word ghusaao
            if(i != words.size()-1){
                result += gap;
            }
        }
        //add remaining spaces at the end
            result += string(extraspaces, ' ');
            return result;
    }
};