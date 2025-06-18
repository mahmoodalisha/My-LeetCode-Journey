class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int today = 0;
        int totaleaten = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> greater<>> appleHeap;

        while(today<n || !appleHeap.empty()){
            //Step 1: Add new apples grown today
            if(today<n && !appleheap.empty()){
                int expiry = today+days[today]-1;
                appleHeap.push({expiry,apples[today]});
            }
            //Step 2: Remove all rotten apples (expired before today)
            while(!appleHeap.empty() && appleHeap.top().first<today){
                appleHeap.pop();
            }
            if(!appleHeap.empty()){
                auto[expiry, count] = appleHeap.top();
                appleHeap.pop();
                totaleaten++;
                if(count>1){
                    appleheap.push({expiry,count-1});
                }
            }
            today++;
        }
        return totaleaten;
    }
};

/*
Heap looks like:

Day	    Heap Before Eating	                Apple Eaten From	        Heap After Eating
0	    {2,1}	                            {2,1}	                            []
1	    {2,2}	                            {2,2} → becomes {2,1}	            {2,1}
2	    {2,1}, {2,3}	                    {2,3} → becomes {2,2}	            {2,2}
3	    {2,2}, {6,5} → remove {2,2}	        {6,5} → becomes {6,4}	            {6,4}
4	    {6,4}, {5,2}	                    {5,2} → becomes {5,1}	            {6,4}, {5,1}
5	    {6,4}, {5,1}	                    {5,1} gone	                        {6,4}
6	    {6,4}	                            {6,4} → becomes {6,3}	            {6,3}
7	    {6,3} expired	                    —	                                []
*/