//Remove all occurence of a string
class Solution{
    public:
        string remove(string s, string part){  //string ki length khatam ho gai hai toh loop se baahar nikal jaao
            while(s.length()!=0 && s.find(part) < s.length()){
                s.erase(s.find(part), part.length());
            }
            return s;
        }
};
//