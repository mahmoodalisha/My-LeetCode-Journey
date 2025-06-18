class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()){
            return false;
        }
        string doubled = s + s;
        for(int i = 0;i<s.length()-goal.length();i++){
            int j = 0;
            for(; j<goal.length();j++){
                if(doubled[i+j] == goal[j]){
                    break;
                }
            }
            if(j == goal.length()){
                return true;
            }
        }
        return false;
    }
};