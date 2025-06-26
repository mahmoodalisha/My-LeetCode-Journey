class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxscore = 0;
        sort(tokens.begin(), tokens.end());

        int i = 0;
        int j = n-1;

        int score = 0;
        while(i<=j){ //power gava ke score badha lo
            if(power>=tokens[i]){
                power -= tokens[i]; //power gava diya
                score += 1; //lekin score badha diya
                i++;

                maxscore = max(maxscore, score); //maxscore ko update kar lo
            }
            else if(score >= 1){ //matlab mere paas power nahi hai itna toh score ko gava do aur power gain karlo
                power += tokens[j];
                score -= 1;
                j--;
            }
            else return maxscore;
        }
        return maxscore;
    }
};
//dry run in my DSA copy