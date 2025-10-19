//BFS
class Solution {
public:

    void rotate(string &s, int b){
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s)+b);
        reverse(begin(s)+b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()){
            string curr = que.front();
            que.pop();

            if(curr<smallestString){
                smallestString = curr;
            }

            //operation 1: Add a to the digits
            string temp = curr;
            for(int i = 1; i<temp.length(); i+=2){ //odd indices par hi operation lagana hai nah isiliye
                temp[i] = ((temp[i]-'0' + a)%10) + '0'; //character to integer me convert karo uski ascii value use karke aur modulo 10 isliye karre hai kyunki 9 ke baad 0 pe chale jaana hai
            }

            if(!visited.count(temp)) {
                visited.insert(temp);
                que.push(temp);
            }
            //operation 2: rotate right by b
            rotate(curr, b);
            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }
        }
        return smallestString;
    }
};

//youtube : code story with MIK