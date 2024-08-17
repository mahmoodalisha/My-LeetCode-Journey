#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 8

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

char nodes[MAX_VERTICES] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
bool visited[MAX_VERTICES] = {false};

// implementing queue for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    int item;
    if (queue->front == -1)
        printf("Queue is empty\n");
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

bool isEmpty(Queue* queue) {
    return queue->rear == -1;
}

void bfs(int start) {
    Queue* queue = createQueue();
    visited[start] = true;
    enqueue(queue, start);
    printf("BFS Traversal: ");

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%c ", nodes[currentNode]);

        for (int i = 0; i < MAX_VERTICES; ++i) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Starting BFS from node A:\n");
    bfs(0); 
    return 0;
}



