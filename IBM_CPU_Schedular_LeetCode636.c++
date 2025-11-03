/*
| Variable             | Meaning                                                 |
| -------------------- | ------------------------------------------------------- |
| `stack<int> mystack` | Keeps **function IDs** of active (unfinished) functions |
| `prevTime`           | Keeps **the last processed timestamp**                  |
| `res[id]`            | Total **exclusive time** spent in function `id`         |
*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> mystack;
        vector<int> result(n, 0);
        int prevtime = 0;

        for(string &log : logs){
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1+1);
            int id = stoi(log.substr(0,pos1));
            string type = log.substr(pos1+1, pos2-pos1-1);
            int time = stoi(log.substr(pos2+1));

            if(type == "start"){
                if(!mystack.empty()){
                    result[mystack.top()] += time-prevtime;
                }
                mystack.push(id);
                prevtime = time;
            } else{
                result[mystack.top()] += time-prevtime+1;
                mystack.pop();
                prevtime = time+1;
            }
        }
        return result;
    }
};

/*
| Log       | Action                      | Stack | result | prevtime |
| --------- | --------------------------- | ----- | ------ | -------- |
| 0:start:0 | push 0                      | [0]   | [0,0]  | 0        |
| 1:start:2 | add time[0]+=2-0=2, push 1  | [0,1] | [2,0]  | 2        |
| 1:end:5   | add time[1]+=5-2+1=4, pop 1 | [0]   | [2,4]  | 6        |
| 0:end:6   | add time[0]+=6-6+1=1        | []    | [3,4]  | 7        |

*/