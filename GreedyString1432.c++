class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string a = s;
        for(char c : s){
            if(c != '9'){
                for(char& x : a){
                    if(x == c)
                    x = '9';
                }
                break;
            }    
        }
        string b = s;
        if(s[0] != '1'){ //If the first digit is not already 1, it replaces all occurrences of that digit with 1, including the first digit itself
            for(char& x : b){
                if(x == s[0])
                x = '1';
            }
        } //this block only runs when s[0] != '1'
        //But if s[0] == '1', then that block is skipped, and we go into the else block
        else{
            for(int i = 1; i< s.size(); i++){
                if(s[i] != '0' && s[i] != '1'){
                for(char&x : b){
                    if(x == s[i])
                    x = '0';
                }
                break;
            }
        }
    }
        return stoi(a) - stoi(b);
    }
};

/* 
if s[0] != '1'	Replace all s[0] with '1' — safe, no leading zero
s[0] == '1' (e.g. "11891")	Can't touch s[0] → look for other digit to replace with '0'



Why start from i = 1?
Because the leading digit is s[0], and we've already decided not to touch it (since it’s '1' in this branch of the logic). We can't change it to '0' — that would create a leading zero, which is not allowed.

So, we look for a digit after the leading one that:

Is not '0'

Is not '1'

And replace all its occurrences with '0' to minimize the number

✅ Example:
Let’s say:
num = 11891  
s = "11891"
s[0] = '1' → already '1', so we don't go into the first block
Go into else block:

s[1] = '1' → skip

s[2] = '8' → valid! not '0' or '1'

Replace all '8' in the number with '0'

So b = "11091"

🔁 Summary:
Variable	Meaning
s[i]	The i-th digit (after first one)
s[0]	Leading digit
Why skip s[0]?	To avoid creating a leading '0', which is invalid
*/