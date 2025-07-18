//sort and keep the intervals based on smallest end day
//so in the min heap keep only the end day

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = events[0][0]; //events ka 0th index se start kardo
        int i = 0; //events pe iterate karne ke liye
        int count = 0;

        while(!pq.empty() || i<n){ //out of bound and empty priority queue check ke liye
        while (i<n && events[i][0] == day){ //starting day agar current day ke barabar ho jaata hai toh priority queue me daalte chale jao
            pq.push(events[i][1]);
            i++;
        }
        if(!pq.empty()){
        pq.pop(); //1 event attended on this day
        count++;
        }
        day++;
        //skip those events whose endDay<day
        while(!pq.empty() && pq.top()<day){ //priority queue ke top me jo element hai matlab jo end day hai wo current day se chhota hai usko hata do
        pq.pop();
        } 
        }
        return count;
    }
};

//youtube : code story with MIK