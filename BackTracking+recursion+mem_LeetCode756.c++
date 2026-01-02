//Pyramid banate chaloo


//unordered map me string vs vector char store kar lo
//allowed = "BCC","BCD","CDE","CEA","FFF"
// "BC" -> {'C', 'D'} 
// "CD" -> {'E'}
// "CE" -> {'A'}
// "FF" -> {'F'}
class Solution {
public:
    unordered_map<string, bool> t; 
    bool solve(string curr_level, unordered_map<string, vector<char>>& mpp, int idx, string above_level){
            //base case
            if(curr_level.length() == 1){ //pyramid ban gaya hum top pe chale aaye
                return true;
            }

            string key = curr_level + "_" + to_string(idx) + "_" + above_level; //3 cheeze change ho rahi hai, ek current level change ho rha hai, ek current index aur ek above level toh 3 parameter hai memoize karo 

            if(t.count(key)){ //kya maine is state ko past me solve kar rakha hai ?
                return t[key]; //memoize karre hai
            }

            if(idx == curr_level.length()-1){ //matlab index , current level ke last tak chala aaya ab upar ke level pe jaao, time to move to the next level
                return t[key] = solve(above_level, mpp, 0, "");
            }
            string pair = curr_level.substr(idx, 2);
            if(mpp.find(pair) == mpp.end()){
                return t[key] = false;
            }
            for(char &ch : mpp[pair]){
                above_level.push_back(ch); //do
                if(solve(curr_level, mpp, idx+1, above_level) == true) return t[key] = true; //explore
                above_level.pop_back(); //undo
            }
            return t[key] = false;
        }

        bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        unordered_map<string, vector<char>>mpp;
        for(auto& i : allowed){
            mpp[i.substr(0, 2)].push_back(i[2]);
        }
        return solve(bottom, mpp, 0, "");
    }
};