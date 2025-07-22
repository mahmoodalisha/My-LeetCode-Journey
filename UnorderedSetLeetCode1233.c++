class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> myset(folder.begin(), folder.end());
        vector<string> result;

        for(string curr : folder){
            bool isSubfolder = false;
            string temp = curr;
            while(!curr.empty()){ //Ham string ke ant (end) se lekar shuruaat (start) tak piche ki taraf iterate kar rahe
                size_t position = curr.find_last_of('/');

                curr = curr.substr(0, position);

                if(myset.find(curr) != myset.end()){
                    //it means curr is a subfolder
                    isSubfolder = true;
                    break; //while loop se baahar nikal jayenge
                }
            }
            if(!isSubfolder){
                result.push_back(temp);
            }
        }
        return result;
    }
};
/*
Input: folder = ["/a", "/a/b", "/c/d", "/c/d/e", "/c/f"]

The set myset will store:
{
  "/a",
  "/a/b",
  "/c/d",
  "/c/d/e",
  "/c/f"
}

| Iteration | Value of `curr` |
| --------- | --------------- |
| 1         | `"/a"`          |
| 2         | `"/a/b"`        |
| 3         | `"/c/d"`        |
| 4         | `"/c/d/e"`      |
| 5         | `"/c/f"`        |

 */

 /*
curr = "/c/d/e"
Ab pos = last '/' ka index = 4
curr = "/c/d"
curr = "/c/d"
Ab pos = 2
curr = "/c"
curr = "/c"
Ab pos = 0, toh break ho jaayega
  */

// youtube : code story with mik