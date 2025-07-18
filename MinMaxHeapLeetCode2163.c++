class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(); //3n
        int leftover = n/3;

        vector<long long>leftMinSum(n, 0);
        vector<long long>rightMaxSum(n, 0);

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for(int i = 0; i<2*leftover; i++){
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if(maxHeap.size()>leftover){
                leftSum -= maxHeap.top(); //largest element remove kar do
                maxHeap.pop();
            }
            leftMinSum[i] = leftSum;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        for(int i = n-1; i>=leftover; i--){
            minHeap.push(nums[i]);
            rightSum += nums[i];
        
        if(minHeap.size()>leftover){
            rightSum -= minHeap.top();
            minHeap.pop();
            }
            rightMaxSum[i] = rightSum;
        }

        long long result = LLONG_MAX;
        for(int i = leftover-1; i<= 2*leftover-1; i++){
            result = min(result, leftMinSum[i]-rightMaxSum[i+1]);
        }
        return result;
    }
};