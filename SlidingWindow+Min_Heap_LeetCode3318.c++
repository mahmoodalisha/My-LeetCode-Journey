//sliding window + Min Heap
class Solution {
public:
    typedef pair<int, int> P;
    int findsum(unordered_map<int, int> freq,int x){
        //min heap to ensure top x elements hi rahe
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto &it : freq){
            pq.push({it.second, it.first});

            if(pq.size()>x){
                pq.pop(); //remove smallest element from the top
            }
        }
        int sum = 0;
        while(!pq.empty()){
            auto [freq, val] = pq.top();
            pq.pop();

            sum += freq*val;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> result;
        int i = 0;
        int j = 0;

        while(j<n){ //khaandani sliding window template
            freq[nums[j]]++;
            if(j-i+1 == k){ //window size k ho gaya, k size ka subarray mil gaya
                result.push_back(findsum(freq, x));
                freq[nums[i]]--; //window shrink kardo
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};