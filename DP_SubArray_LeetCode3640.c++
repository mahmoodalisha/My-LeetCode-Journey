//total trend 0, 1, 2, 3 hai
//trend 0 matlab kuch nahi choose kiya
//trend 1 matlab  increasing
//trend 2 matlab  decreasing
//trend 3 phir se increasing

class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums){
        //base case
        if(i == n){
            if(trend == 3){ //kya aap trend 3 tak pahunch gaye
                return 0; //no more elements, you reached out of bound
            }
            else{ //trend 3 takpahunche nahi galat path pe aa gaye
                return LLONG_MIN/2;
            }
        }

        if(memo[i][trend] != LLONG_MIN){
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(trend == 0){
            skip = solve(i+1, 0, nums);
        }

        //i m at trend 3 and now can end at nums[i]
        if(trend == 3){
            take = nums[i];
        }

        if(i+1 < n){
            int curr = nums[i];
            int next = nums[i+1]; //dhyan rakhna ye out of bound nahi ho jaye 

            //ab mai trend 0 par hu aur mujhe trend 1 start karna hai
            if(trend == 0 && next > curr) { //trend 1 start karne ke liye next , current se bada hona chahiye
                take = max(take, curr + solve(i+1, 1, nums));
            }
            else if(trend == 1){
                if(next > curr){
                    take = max(take, curr + solve(i+1, 1, nums));
                }
                else if(next < curr){ //decreasing ka trend hai ye
                    take = max(take, curr + solve(i+1, 2, nums)); //trend 2 ab start kardo 
                }
            } else if(trend == 2){
                if(next < curr){
                    take = max(take, curr + solve(i+1, 2, nums));
                }
                else if(next > curr){ //decreasing ka trend hai ye
                    take = max(take, curr + solve(i+1, 3, nums)); //trend 2 ab start kardo 
                }
            }
            else if(trend == 3 && next > curr){
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        memo.assign(n+1, vector<ll>(4, LLONG_MIN)); //4 trend ho sakte hai
        return solve(0, 0, nums); //i, trend
    }
};


/*============================================================================================*/

//Easy Question of this one is LeetCode 3637

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        if(n<4) return false;

        int i = 1;
        //strictly increasing
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i==1 || i==n) return false;
        //strictly decreasing
        while(i<n && nums[i]<nums[i-1]){
            i++;
        }
        if(i==n) return false;
        //again strictly increasing
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }

        return i==n;
    }
};