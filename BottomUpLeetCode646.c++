/*leetcode 300 LIS variant
[[1,2],[2,3],[3,4]]
[1,2]and[3,4] only this pair works becoz 2<3
[1,2]and[2,3] this will not work becoz 2=2

again [[1,2],[7,8],[4,5]] sort them
[[1,2][4,5],[7,8]] here 2<4 and5<7
*/
//so compare pair[1] element with pair[0]
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> t(n,1);
        int maxL = 1;

        for(int i = 1; i< n; i++){
            for(int j = 0; j<i; j++){
                if(pairs[j][1]<pairs[i][0]){
                        t[i] = max(t[i], t[j]+1);
                        maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }
};