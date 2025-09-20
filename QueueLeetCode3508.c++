class Router {
public:
    unordered_map<string, vector<int>> packets; //key is the string that stores S, D, T
    unordered_map<int, vector<int>> destn;
    queue<string> que;

    string makeKey(int S, int D, int T){
        return to_string(S) + "#" + to_string(D) + "#" + to_string(T);

    }

    int MAX_SIZE;
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }


    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if(packets.find(key) != packets.end()){
            return false;
        }
        if(que.size()>=MAX_SIZE){
            forwardPacket();
        }
        packets[key] = {source, destination, timestamp};
        que.push(key);
        destn[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packets.empty()){
            return {};
        }
        string key = que.front();
        que.pop();

        vector<int> packet = packets[key]; //isme S, D, T hai
        packets.erase(key);

        int D = packet[1];
        destn[D].erase(destn[D].begin());

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destn.find(destination);
        if(it == destn.end() || it -> second.empty()){
            return 0;
        }
        vector<int> &timeStamps = it->second; //{T1, T2, T3}
        int i = lower_bound(begin(timeStamps), end(timeStamps), startTime) - begin(timeStamps);
        int j = upper_bound(begin(timeStamps), end(timeStamps), endTime) - begin(timeStamps);
        return j - i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */