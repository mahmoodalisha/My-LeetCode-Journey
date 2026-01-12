class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map <int, int> map;
            for (int i = 0; i<answers.size(); i++){
                map[answers[i]]++;  //just to count occurence of each no
            }
            int total = 0;
            unordered_map <int, int>:: iterator it;
            for (it = map.begin(); it != map.end(); it++){
                int answer = it -> first;  // The answer given by rabbits
                int count = it -> second;  // Number of rabbits who gave this answer

                total += ceil((double)count / (answer + 1))*(answer+1);
            }
            return total;
        }
    };       

    /* p.first: This represents the answer given by a group of rabbits. For example, if a rabbit answers "2", then p.first is 2. 
p.second: This represents how many rabbits gave the same answer. For example, if there are 3 rabbits who answered "2", then p.second will be 3

(double)p.second / (p.first + 1): This calculates how many full groups of size (p.first + 1) (group size) are needed to fit all the rabbits who gave this answer.
For example, if p.first = 1 (answer "1") and p.second = 4 (4 rabbits gave this answer), then the group size is 1 + 1 = 2.
Now, 4 / 2 = 2 full groups are needed 

[1, 1, 2]
map[1] = 2 → Two rabbits answered "1"
map[2] = 1 → One rabbit answered "2"
So, the loop will iterate:
For answer = 1, count = 2 

Each it points to a pair<int, int>, where:
it->first is the key (in your case, the rabbit's answer),
it->second is the value (how many times that answer occurred).
*/