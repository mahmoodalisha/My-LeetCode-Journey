class Solution {
public:
    bool isValid(string word) {
        if (word.length()<3) return false;
        bool hasVowel = false;
        bool hasConsonent = false;

        for(char c : word){
            if(!isalnum(c)) return false; //isalnum check karta hai ki kya character ek letter ya digit hai.
            //Agar kuch aur (jaise #, @, etc.) mile, to return false.

            if(isalpha(c)){//isalpha check karta hai ki kya character ek letter hai (a–z ya A–Z) Agar digit hai (0–9), to false dega.
                char lower = tolower(c); //Agar letter hai, to use chhoti letter (small letter) mein convert karte ho tolower(c) se — taaki 'A' aur 'a' dono ko same treat karo.
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
                    hasVowel = true;
                }
                else {
                    hasConsonent = true;
                }
            }
        }
        return hasVowel && hasConsonent;
    }
};
/*
1. isalnum(c) se hum pehle digit ya letter check karte hain.
➡️ Haan! Agar c digit ya letter hai to chalega.
Agar c koi special character ho (@, #, %, etc.) → turant false return kar dena hai.

2. phir aage badhte hai check karte hai ki current c digit toh nahi kyun ki digit vowel/consonent nahi ho sakta,
phir saath me return kar dete hai
*/