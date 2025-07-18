class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int pairSize = n-1;
        vector<int> pairSum(pairSize, 0);
        for(int i = 0; i<pairSize; i++){
            pairSum[i] = weights[i]+weights[i+1];
        }
        sort(pairSum.begin(), pairSum.end());
        long maxSum = 0;
        long minSum = 0;
        for(int i = 0; i<k-1; i++){//k-1 pair mil jayenge
            minSum += pairSum[i]; //starting element
            maxSum += pairSum[pairSize-1-i]; //ending element
        }
        return maxSum - minSum;
    }
};//all dry run in my DSA copy