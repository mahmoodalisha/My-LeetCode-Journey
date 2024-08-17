#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rearIndex;
    int size;

public:
    // Constructor
    Queue(int maxSize) {
        size = maxSize;
        arr = new int[size];
        frontIndex = 0;
        rearIndex = 0;
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Add an element to the queue
    void enqueue(int data) {
        if (rearIndex == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rearIndex] = data;
            rearIndex++;
        }
    }

    // Remove an element from the queue
    int dequeue() {
        if (frontIndex == rearIndex) {
            cout << "Queue is empty" << endl; 
            return -1;
        } else {
            int ans = arr[frontIndex];
            arr[frontIndex] = -1; // Deleting the first element of the queue
            frontIndex++;
            if (frontIndex == rearIndex) { //first element front pe hai, wo delete karne ke baad front aur rear toh equal ho jayega, toh usko reset kardo
                frontIndex = 0;
                rearIndex = 0;
            }
            return ans;
        }
    }

    // Get the front element of the queue
    int getFront() {
        if (frontIndex == rearIndex) {
            return -1;
        } else {
            return arr[frontIndex];
        }
    }

    // Print the elements of the queue
    void printQueue() {
        if (frontIndex == rearIndex) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = frontIndex; i < rearIndex; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    
    Queue queue(size);

    int choice, data;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the data to enqueue: ";
            cin >> data;
            queue.enqueue(data);
            break;
        case 2:
            data = queue.dequeue();
            if (data != -1) {
                cout << "Dequeued element: " << data << endl;
            }
            break;
        case 3:
            queue.printQueue();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
