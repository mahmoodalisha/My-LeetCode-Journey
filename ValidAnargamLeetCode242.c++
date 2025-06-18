class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int count[26] = {0};  //array of 26 characters, in this step the compiler doesnt know about the character from a to z

        for(int i = 0; i<s.length();i++){
            count[s[i] - 'a']++; //but in this step the compiler gets the a to z characters assigned due to the ascii
            count[t[i] - 'a']--;
        }
        // Check if all counts are 0
        for (int i = 0; i < 26; i++) {
        if(count[i] != 0){
            return false;
        }
    }
        return true;
    }
}; 


/*
Table Example for s = "anagram" and t = "nagaram"

i	    s[i]	t[i]	s[i] - 'a'	    t[i] - 'a'	    Action	                        Count array (changes)
0	    a	    n	    0	            13	            count[0]++, count[13]--	        a: +1, n: -1
1	    n	    a	    13	            0	            count[13]++, count[0]--	        n: 0, a: 0
2	    a	    g	    0	            6	            count[0]++, count[6]--	        a: +1, g: -1
3	    g	    a	    6	            0	            count[6]++, count[0]--	        g: 0, a: 0
4	    r	    r	    17	            17	            count[17]++, count[17]--	    r: 0
5	    a	    a	    0	            0	            count[0]++, count[0]--	        a: 0
6	    m	    m	    12	            12	            count[12]++, count[12]--	    m: 0

➡️ Final count array = all 0 → ✅ It is an anagram
 */