//greedy approach TC : O(n) single pass left-to-right and right-to-left
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answer(n,n); // initialize distances with large value (n)
        int prev = -n; // start far away (no 'c' seen yet)


        // Pass 1: Left → Right
        for(int i = 0; i<n; i++){
            if(s[i] == c)
            prev = i; // found a 'c', remember its index
            answer[i] = i-prev; // distance from last seen 'c'
        }

        // Pass 2: Right → Left
        prev = 2*n;
        for(int i = n-1; i>=0; i--){
            if(s[i] == c)
            prev = i; //found a 'c' from the right side
            answer[i] = min(answer[i], prev-i); //take the smaller distance
        }
        return answer;
    }
};