class Solution {

    void dfs(int curr, int n, vector<int>& ans){
            if(curr>n) return;

            ans.push_back(curr);

            for(int i = 0; i<=9; ++i)
            dfs(curr*10+i, n, ans);
        }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<=9; ++i){
            dfs(i,n,ans);
        }
        return ans;
    }
}; 

/* 
Suppose n = 13.
Start with curr = 1, and go deeper:
dfs(1) → OK (1 <= 13)
dfs(10) → OK (10 <= 13)
dfs(100) → Not OK (100 > 13) → stop here

So, we do not call dfs(1000), dfs(1001)... etc.
That’s because:
dfs(100) hits the if (curr > n) condition and returns without going into for (int i = 0; i <= 9; ++i) at all. 


Depth	curr	i in loop	    curr * 10 + i	        ans
0	    1	    loop: 0→9	    10	                    [1]
1	    10	    loop: 0→9	    100	                    [1, 10]
2	    100	    -	            > n (stop)	            [1, 10]
1	    10	    i = 1	        101 > n (stop)	
1	    10	    i = 2	        102 > n (stop)	
...	...	...	...	
1	    10	    i = 9	        109 > n (stop)	
Back	1	    i = 1	        11	[1, 10, 11]
2	    11	    loop: 0→9	    110 > n (stop)	
Back	1	    i = 2	        12	                    [1, 10, 11, 12]
2	    12	    loop: 0→9	    120 > n (stop)	
Back	1	    i = 3	        13	                    [1, 10, 11, 12, 13]
2	    13	    loop: 0→9	    130 > n (stop)	
Back	1	    i = 4	        14 > n (stop)	
...	    1	    i = 5-9	        15-19 > n (stop)	


youtube: techdose
*/