//Combinations
class Solution {
public:
    vector<vector<int>> result;  //i will store my result
     void solve(int start,int n, int k, vector<int>& temp){
        if (k==0){  //when you reach eand of recursion tree
            result.push_back(temp);
            return;
        }
        if(start>n) //start greater than n nahi hona chahiye
            return;
            temp.push_back(start);
            solve(start+1,n,k-1, temp);
            temp.pop_back();
            solve(start+1,n,k, temp);//k ko pop kar liya hai
        
     }
    vector<vector<int>> combine(int n, int k) {
          vector<int>temp;
          solve(1, n, k, temp);
          return result;
    }
};