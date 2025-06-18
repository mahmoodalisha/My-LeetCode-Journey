/*
DRY RUN:
citations = [3, 0, 6, 1, 5]  // total papers = 5 → n = 5

Looping through:
- c = 3 → bucket[3]++  Since 3 <= n, we do: bucket[3]++  bucket becomes: [0, 0, 0, 1, 0, 0]
- c = 0 → bucket[0]++  Since 0 <= n, we do: bucket[0]++  bucket becomes: [1, 0, 0, 1, 0, 0]
- c = 6 → bucket[5]++   // because 6 >= 5, we do bucket[n]++
- c = 1 → bucket[1]++
- c = 5 → bucket[5]++
bucket = [1, 1, 0, 1, 0, 2]
index   =  0  1  2  3  4  5
1 paper has 0 citations.
1 paper has 1 citation.
1 paper has 3 citations.
2 papers have ≥5 citations
*/

//youtube: codebix
//The H-index is the maximum value h such that the researcher has at least h papers with h or more citations each

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n+1, 0);// n+1 size ka array

        //count the no. of citations
        for(int c : citations){
            if(c>=n){
                bucket[n]++;
            }
            else bucket[c]++;
        }
    
    //Traverse from the back to find h-index
    int count = 0;
    for(int i = n; i>=0; i--){
        count+=bucket[i];
        if(count >= i){
            return i;
        }
    }
    return 0;
    }
};