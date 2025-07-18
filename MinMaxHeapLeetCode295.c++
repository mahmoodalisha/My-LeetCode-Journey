class MedianFinder {
public:

    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num<left_max_heap.top()){
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        //always maintain left_max_heap size one greater than right_min_heap
        //ya fir dono ka size equal ho 
        if(abs((int)left_max_heap.size()-(int)right_min_heap.size())>1){ //agar size equal nahi hai toh
        right_min_heap.push(left_max_heap.top()); //isse dono ki size equal ho jayegi
        left_max_heap.pop();
        } else if(left_max_heap.size()<right_min_heap.size()) { //ye case to hona hi nahi chahiye bilkul bhi
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()){ //iska matlab even no of elements hai to mean nikaaal lo
            double mean = (left_max_heap.top()+right_min_heap.top())/2.0;
            return mean;
        }
        //else odd no of elements hai
        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */