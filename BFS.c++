#include <bits/stdc++.h>
using namespace std;

class Queue {
    int front, rear, size;
    int *arr;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) return;   // queue full (ignore)
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (front > rear) return -1;    // queue empty
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }
};

void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    Queue q(n);

    visited[start] = true;
    q.enqueue(start);

    while (!q.isEmpty()) {
        int node = q.dequeue();

        cout << node << " ";   // process node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.enqueue(neighbor);
            }
        }
    }
}




/*===============================================================================================*/

void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";   // process the node (can remove if not needed)

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}