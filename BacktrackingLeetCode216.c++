class Solution {
public:

    void backtrack(int index, int k, int n, vector<int>& ds, vector<vector<int>>& ans){
        if(k == 0 && n == 0){
            ans.push_back(ds);
            return;
        }

        if(k < 0 || n < 0) return;

        for(int i = index; i<= 9; i++){
            
                ds.push_back(i);
                backtrack(i+1, k-1, n-i, ds, ans);
                ds.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        backtrack(1, k, n, ds, ans);   // Start from 1
        return ans;
    }
}; 

/*
🔁 Dry Run Example:
Let’s assume: k = 3, n = 7

Step 1:
ds = [], k = 3, n = 7
Try i = 1

Step 2:
ds = [1], k = 2, n = 6
Try i = 2

Step 3:
ds = [1, 2], k = 1, n = 4
Try i = 4

Step 4:
ds = [1, 2, 4], k = 0, n = 0 so i have reached till the end and  so i am getting a combination of size k

 */