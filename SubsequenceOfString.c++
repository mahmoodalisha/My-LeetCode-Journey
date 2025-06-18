//Subsequences of String using recursion

void solve(string str, string output, int index, vector<int>& ans){
    //base case
    if ( index >= str.length()){
        ans.push_back(output);
        return; 
    }

    //exclude
    solve(str, output, index + 1, ans);

    //include
    char element = str[index];  //storing in this variable
    output.push_back(element);
    solve(str, output, index + 1, ans);
}
vector<string> subsequence(string str){
    vector <string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}