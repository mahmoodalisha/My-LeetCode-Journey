class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = (n+2LL)*(n+1)/2; //res now stores all possible ways to distribute n candies to 3 children without any limits
        for(int i = 1; i<=3; i++){
            long long rem = n-1LL*i*(limit+1);//We're calculating how many candies are left if i children are forced to get at least m+1 candies i.e violate the limit
            if(rem<0) break;  //If not enough candies left, break out — no more valid cases.
            long long val = (rem + 2) * (rem + 1) / 2; //Number of ways to distribute rem candies among 3 children
            long long c = (i<3?3:1);
            res += (i % 2 ? -c * val : c * val);
        }
        return res;
    }
};

/*DRY RUN
Let’s say:
n = 7 candies
limit = 2

We’re looping i from 1 to 3 (up to 3 children breaking the rule):
Case i = 1:
One child takes at least 3 candies
Remaining candies: 7 - 1*3 = 4

We now compute how many ways to distribute 4 candies among 3 children (including the violating child)
But these distributions are invalid because one child broke the rule.
So we compute how many such distributions exist and subtract them.

Case i = 2:
Two children break the rule, each taking ≥3
Used: 2*3 = 6, remaining: 7 - 6 = 1
Still some distributions possible — now we add these back because they were subtracted multiple times earlier (inclusion-exclusion fix).

Case i = 3:
All three children break the rule: 3*3 = 9
But n = 7, so rem = 7 - 9 = -2 → invalid → we break out of the loop

long long rem = n - 1LL * i * (limit + 1);
if (rem < 0) break;
mean:"Assume i children are breaking the rule by taking more than limit candies. See if the remaining candies (rem) are non-negative. If not, stop checking — it's impossible."

The idea is to subtract these illegal cases from the total using inclusion-exclusion.

