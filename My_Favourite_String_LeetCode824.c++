class Solution {
public:

    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }

    string toGoatLatin(string sentence) {
        int n = sentence.size();
        string result = "";
        string word;
        int index = 1; //word number
        stringstream  ss(sentence);
        //The >> operator automatically splits by spaces — no need to write any .substr() or find() logic yourself. Instead of manually looping and checking for spaces ' ', we can simply do while (ss >> word) {
    // each loop, word = next word in the string}


        while(ss >> word){
            if(isVowel(word[0])){
                word += "ma";
            }
            else{ //move the first letter to the end
                word = word.substr(1) + word[0] + "ma";
            }
            //now add 'a' index times
            word += string(index, 'a');

            if(!result.empty()) result += " "; //add space before next word
            result += word;

            index++;
        }
            return result;
    }
};