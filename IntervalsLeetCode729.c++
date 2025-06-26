class MyCalendar {
public:
    set<pair<int, int>> st;
    
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        auto it = st.lower_bound({startTime, endTime}); // Log(N)

        // Check overlap with next event
        if(it != st.end() && it->first < endTime) {
            return false;
        }

        // Check overlap with previous event
        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(startTime < prevIt->second) {
                return false;
            }
        }

        st.insert({startTime, endTime});
        return true;
    }
};
//youtube: code story with MIK