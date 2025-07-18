//store the meetings in a min heap and unused rooms in another min heap
//top pe sabse chooti value
class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        vector<int> roomsUsedCount(n, 0); //array to keep a track of rooms with the most meetings that we need to return

        priority_queue<P, vector<P>, greater<P>> usedRooms;

        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for(int room = 0; room<n; room++){
            availableRooms.push(room); //abhi saare rooms available hai toh daal do
        }
        for(vector<int>& meet : meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end-start;

            while(!usedRooms.empty() && usedRooms.top().first <= start){ //current meeting ke start hone se pehle agar uska start chota hai
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){ //we have rooms available
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else{ // we dont have any rooms available so pick earliest one from the availablerooms heap
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first; //ye wala room jaldi khaali ho jayega

                usedRooms.pop();
                usedRooms.push({endTime+duration, room});
                roomsUsedCount[room]++;
            }
        }
        int maxCount = -1;
        int resultRoom = 0;
        for (int i = 0; i<n; i++){
            if(roomsUsedCount[i] > maxCount){
                maxCount = roomsUsedCount[i];
                resultRoom = i;
            }
        }
        return resultRoom;
    }
};

//dry run for the min Heap in my DSA copy youtube : code story with MIK
//So each item in usedRooms is a pair like: {endTime, roomNumber}
