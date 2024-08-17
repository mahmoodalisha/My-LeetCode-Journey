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

void iterative_dfs(int start_node) {
    int stack[MAX_VERTICES];
    int top = -1;
    stack[++top] = start_node;

    while (top >= 0) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = true;
            printf("%c ", nodes[node]);

            for (int i = MAX_VERTICES - 1; i >= 0; --i) {
                if (graph[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    printf("DFS Traversal Order: ");
    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (!visited[i]) {
            iterative_dfs(i);
        }
    }
    printf("\n");
    return 0;
}



