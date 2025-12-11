/*
🗺️ Visual Example
Input:
n = 3
buildings = [
    [1,2],
    [2,2],
    [3,2],
    [2,1],
    [2,3]
]


Let’s visualize the city grid:

    y=1  y=2  y=3
x=1   .   B   .
x=2   B   B   B
x=3   .   B   .


Where B means building.
🏗️ What goes inside rows
We scan every building:
For building (1,2):
rows[1].push_back(2)
For building (2,2):
rows[2].push_back(2)
For building (3,2):
rows[3].push_back(2)
For building (2,1):
rows[2].push_back(1)
For building (2,3):
rows[2].push_back(3)
So the map looks like:

rows = {
    1: [2],
    2: [2,1,3],
    3: [2]
}


Meaning:
Row 1 has a building at y=2
Row 2 has buildings at y=1,2,3
Row 3 has a building at y=2
🏢 What goes inside cols

We do the same but grouped by columns:
For building (1,2):
cols[2].push_back(1)
For building (2,2):
cols[2].push_back(2)
For building (3,2):
cols[2].push_back(3)
For building (2,1):
cols[1].push_back(2)
For building (2,3):
cols[3].push_back(2)

So:

cols = {
    2: [1,2,3],
    1: [2],
    3: [2]
}


Meaning:

Column 2 has buildings at x=1,2,3
Column 1 has a building at x=2
Column 3 has a building at x=2

🧭 How this helps find coverage
Take building (2,2).
Look at its row:
rows[2] = [1,2,3]
Sorted means:
y=1  y=2  y=3
Left neighbor → any y < 2? Yes → 1
Right neighbor → any y > 2? Yes → 3
Look at its column:
cols[2] = [1,2,3]
Sorted:

x=1  x=2  x=3

Above neighbor → any x < 2? Yes → 1
Below neighbor → any x > 2? Yes → 3
This building is covered.

🧭 Check any other building

Example: (1,2)

Same row: rows[1] = [2]
→ No left
→ No right

So it’s NOT covered.

*/

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;

        //group buildings by row and col
        for(auto &b : buildings){
            int x = b[0], y = b[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }
        for (auto &p : row) {
            sort(p.second.begin(), p.second.end());
        }
        for (auto &p : col) {
            sort(p.second.begin(), p.second.end());
        }
        int covered = 0;
        for(auto &b : buildings){
            int x = b[0], y = b[1];
            auto &r = row[x];
            auto &c = col[y];

            //find y in row
            int i = lower_bound(r.begin(), r.end(), y) - r.begin();
            bool left = (i > 0);
            bool right = (i+1 < r.size());

            //find x in column
            int j = lower_bound(c.begin(), c.end(), x) - c.begin();
            bool down = (j>0);
            bool up = (j + 1 < c.size());

            if(left && right && up && down) covered++;
        }
        return covered;
    }
};