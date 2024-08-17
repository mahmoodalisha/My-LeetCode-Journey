#include<iostream>
#incllude<std>;
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int maxSize) {
        size = maxSize;
        arr = new int[size];
        front = rear =-1;
    }

    bool enqueue(int value){
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "Queue is Full, sorry dude" << endl;
            return false;
        } else if (front == -1){  //first element aaya hai push karne ke liye
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == size-1  && front != 0){  //rear jo hai wo end me hai, usme push karna hai element
            rear = 0;   //to maintain cyclic nature
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] == value;
        }
         return true;   
    }
    int dequeue() {
        if (front ==  -1){
            cout << "Queue is empty" << endl;
            return -1;
        } 
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear) {  //single element hai
            front = rear = -1;
        }

        else if (front = size-1){ //front end pe pahunch chuka hai
            front = 0; //to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

}