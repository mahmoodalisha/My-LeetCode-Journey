//step 1 : Time vs meetings ka ordered map bana lo, meeting me person 1, person 2 hai isi liye pair lo, aur array hai toh vector of pairs
//step 2 : adjacency list banao, isse pata chalega kiska kiske saath meeting hai
//step 3 : BFS ya DFS se traverse karke dekhlo
//we are taking queue so that people dont repeat in the answer
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<P>> timeMeetings;
        //map banalo time vs meeting ka
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];

            timeMeetings[time].push_back({person1, person2});
        }
        // person0 aur person1 ko secret pehle hi pata hai
        vector<bool> knowssecret(n, false);
        knowssecret[0] = true;
        knowssecret[firstPerson] = true;
        //ab jo map humne banaya isme traversal maaro
        for(auto &it : timeMeetings){
            int t           = it.first;  //key
            vector<P> meets = it.second; //value

            //ab adjacency list bana lo ek person kitno ke saath meeting kar raha hai
            unordered_map<int, vector<int>> adj; //a -> {a, b, c, d}
            queue<int> q;
            unordered_set<int> myset; //taaki dobara persons add nahi ho jaye
            for(auto& [person1, person2] : meets){
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(knowssecret[person1] == true && myset.find(person1) == myset.end()){
                    q.push(person1);
                    myset.insert(person1);
                }

                if(knowssecret[person2] == true && myset.find(person2) == myset.end()){
                    q.push(person2);
                    myset.insert(person2);
                }
            }
            //now i know who meets whom based on the adjacency list
            //now spread the news with BFS

            while(!q.empty()){
                int person = q.front();
                q.pop();

                for(auto &nextPerson : adj[person]){
                    if(knowssecret[nextPerson] == false){
                        knowssecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }
        vector<int> result;
        for(int i = 0; i<n; i++){
            if(knowssecret[i] == true){
                result.push_back(i);
            }
        }
        return result;
    }
};