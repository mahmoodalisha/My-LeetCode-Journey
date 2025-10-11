/* Bottom Up Approach DP
Input power = [2, 3, 3, 5]

Step 1: maxVal ka role
Pehle hume yeh jaanna hai ki numbers kis range tak ja rahe hain.
maxVal = maximum number in array.
maxVal = 5 (kyunki sabse bada number 5 hai)
Hum apna DP aur freq array uske size ke hisaab se banate hain:
vector<long long> freq(maxVal + 1, 0); // index 0..5
freq ek helper array hai jo batata hai:
har number ka “total damage” kitna hai.

| Number | Count | Total Damage = Number × Count |
| ------ | ----- | ----------------------------- |
| 2      | 1     | 2                             |
| 3      | 2     | 6                             |
| 5      | 1     | 5                             |

freq = [0, 0, 2, 6, 0, 5];
Matlab:
Agar hum 2 choose karein → 2 damage milega
Agar hum 3 choose karein → 6 damage milega
Agar hum 5 choose karein → 5 damage milega

2️⃣ dp array kya karta hai
dp ek decision + result array hai.
dp[i] = maximum damage possible agar hum number i se start karein (ya uske baad ke sab numbers consider karein).
Ab dp me hum decisions lete hain:
ya toh number i skip kar lo
ya number i choose kar lo
aur dono me se maximum lo.

dp[i] = max(
    dp[i+1],                // skip i
    freq[i] + dp[i+3]       // take i → skip ±1, ±2 → next allowed i+3
)

Two choices:
Skip i → dp[i] = dp[i+1]
Take i → dp[i] = freq[i] + dp[i+3] (next allowed number after forbidden ±2)
Bottom-up fill karte hai, end me dp[0] answer hai.
*/

class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll> freq;
        
        for(int &c : power){
            freq[c]++;
        }

        vector<ll> nums;
        nums.reserve(freq.size());
        for(auto &it : freq){
            nums.push_back(it.first);
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<ll> dp(n, 0);

        ll result = INT_MIN;

        for(int i = n-1; i>=0; i--){
            ll skip = (i+1 < n) ? dp[i+1] : 0; //out of bound ho jaye toh 0 assign kardo
            int j = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin(); //j ka matlab hai:Agar hum nums[i] choose kar lete hain,to next allowed number (jo forbidden range ke bahar ho) ka index j me store hota hai.
            ll take = nums[i]*freq[nums[i]]+ ((j<n) ? dp[j] : 0);//j bhi out of bound ho sakta hai 
            dp[i] = max(skip, take);
            result = max(result, dp[i]);
        }
        return result;
    }
};
/*
✅ So j ka kaam:
DP me jump karna next non-conflicting number ke index tak.
Kyuki agar hum nums[i] le lete hain, to:
nums[i]+1 aur nums[i]+2 forbidden hain
next safe number = nums[i]+3 ya usse bada. Thus j ka kaam hai “next safe number” (yaani next non-conflicting index) ko dhoondhna.

So agar tum nums[i] lete ho:
Tum nums[i] * freq[nums[i]] ka damage add karte ho,
aur fir dp[j] add karte ho (jo next safe index se future ka best result deta hai).

dp[i] = max(skip, take)


nums array me kya store kar rahe hai ?
maanlo input power = [3, 3, 4, 4, 4, 6]
toh pehle frequency nikalte hai
freq[3] = 2
freq[4] = 3
freq[6] = 1
Therefore nums = [3, 4, 6]
*/