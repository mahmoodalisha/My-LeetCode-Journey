//circular array me last element ka next words[(i + 1) % n] hota hai
//aur first element ka previous handle karne ke liye words[(i - 1 + n) % n] hota hai
//start index se target pe jaana hai isi me decide karna hai kis taraf jaau jo ki minimum travel karna pade
//array me ek-ek string ek-ek index hai
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;
        
        for(int i = 0; i<n; i++){
            if(words[i] == target){
                int straightDist = abs(i-startIndex);
                int circularDist = n-straightDist;

                result = min({result, straightDist, circularDist});
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};