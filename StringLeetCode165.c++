class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int m = version1.size();
        int n = version2.size();

        while(i<m || j<n){
            int start1 = i;
            while(i<m && version1[i] != '.')i++;
            string revision1 = version1.substr(start1, i-start1);
            int num1 = revision1.empty() ? 0 : stoi(revision1);

            int start2 = j;
            while(j<n && version2[j] != '.')j++;
            string revision2 = version2.substr(start2, j-start2);
            int num2 = revision2.empty() ? 0 : stoi(revision2);

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;

            // skip the '.' if still inside string
            if (i < m && version1[i] == '.') i++;
            if (j < n && version2[j] == '.') j++;
        }
        return 0;
    }
};