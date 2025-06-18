class Solution {
public:
    int maxDepth(string s) {
        int current = 0;
        int maxDepth = 0;

        for(char c : s){
            if(c == '('){
                current++;
                maxDepth = max(maxDepth, current);
            }
            else if(c == ')'){
                current--;
            }
        }
        return maxDepth;
    }
};

/* 
Index	Char	What Happens	                Current Depth	Max Depth
0	    (	    Open 1st → increase depth	        1	            1
3	    (	    Open 2nd → increase depth	        2	            2
7	    )	    Close → decrease depth	            1	            2
9	    (	    Open 3rd → increase depth	        2	            2 ✅
10	    (	    Open 4th → increase depth	        3	            3 ✅

*/