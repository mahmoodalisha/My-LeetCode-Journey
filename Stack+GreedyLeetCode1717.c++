class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Decide which pair to remove first based on higher score
        string firstPair = (x >= y) ? "ab" : "ba";
        int firstScore = max(x,y);

        string SecondPair = (x >= y) ? "ba" : "ab";
        int secondScore = min(x, y);

        // First pass: remove firstPair greedily
        stack <char> mystack;
        int score = 0;
        for(char c : s){
            if(!mystack.empty() && mystack.top() == firstPair[0] && c == firstPair[1]){
                mystack.pop(); // remove the matching pair
                score += firstScore;
            } else {
                mystack.push(c); // keep character if not forming the pair
            }
        }
        // Build remaining string from stack
        string remaining;
        while (!mystack.empty()) {
            remaining += mystack.top();
            mystack.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Second pass: remove secondPair
        for (char c : remaining) {
            if (!mystack.empty() && mystack.top() == SecondPair[0] && c == SecondPair[1]) {
                mystack.pop();
                score += secondScore;
            } else {
                mystack.push(c);
            }
        }
        return score;
    }
};
/*
Greedy Strategy (2-step approach)
First Iteration → Remove all pairs with the higher score ("ab" or "ba" depending on x and y)

Use a stack to remove as many of these as possible.
This ensures we maximize the score early by picking the most valuable option.

If x < y, we transform the string to make "ab" the more valuable one (via swap + reverse + flip a↔b), so we always remove "ab" first.

Second Iteration → Remove all remaining pairs of the other kind
Whatever is left (in the stack) is scanned again (in reverse) to remove the less valuable pair.

Again, we use a stack for pair matching.

 */