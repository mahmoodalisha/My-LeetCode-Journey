class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;   // To store valid folder names
        string temp = "";       // To store each folder name from the path

        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                // When we hit a '/', process the current temp if it's not empty
                if (temp == "..") {
                    if (!stack.empty()) stack.pop_back();  // Go back one directory
                } else if (temp != "" && temp != ".") {
                    stack.push_back(temp);  // Valid directory name
                }
                temp = "";  // Reset temp for the next segment
            } else {
                temp += path[i];  // Build the current folder name
            }
        }

        // Last part (if path doesn't end with '/')
        if (temp == "..") {
            if (!stack.empty()) stack.pop_back();
        } else if (temp != "" && temp != ".") {
            stack.push_back(temp);
        }

        // Build the simplified path
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        // If result is empty, we are at root "/"
        return result.empty() ? "/" : result;
    }
};
