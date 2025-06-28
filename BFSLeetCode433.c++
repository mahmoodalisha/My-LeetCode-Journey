class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());//bank se saare strings ko utha ke set me daal diya bank vector me tha quick access ke liye
        unordered_set<string> visited; //all DRY RUN in my DSA copy
        queue<string>que;
        que.push(startGene); //start string se start karo queue me daal do
        visited.insert(startGene); //queue me daal diye matlab visit ho chuka
        int level = 0;
        //now apply BFS
        while(!que.empty()){
            int n = que.size();
            while(n--){//ye while loop current level ke liye
                string curr = que.front();
                que.pop();
                if(curr == endGene) return level; //pura level return kardo

                for(char ch : "ACGT"){
                    for(int i = 0; i<curr.length(); i++){
                        string next_level = curr;
                        next_level[i] = ch; //first try with A fir jab loop aage badhega then C, G, T
                        if (visited.find(next_level) == visited.end() && bankset.find(next_level) != bankset.end())
{ //visit to nahi kar rakha hai and bank set me available hai
                        visited.insert(next_level);
                        que.push(next_level);

                        }
                    }
                }
            }
            level++; //ye pura level explore ho gaya next level
        }
        return -1;
    }
};