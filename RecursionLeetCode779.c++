class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1){ //this is 1st row 1st character base case
            return 0;
        }
        int length = pow(2,n-1); //find the length of the row built till now
        int mid = length/2;
    if(k<=mid){
        return kthGrammar(n-1,k);
        }
    return !kthGrammar(n-1, k-mid); //else return this
    }
};
//T.C : O(N)
//S.C : O(N) Stack space
//youtube: code story with MIK
//for dry run check gallery screenshot