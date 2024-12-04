#include <stdio.h>
#include <stdlib.h>

void bfs(int** adj, int* visited, int start, int max) {
    int queue[max], rear = -1, front = -1, i;

    for (i = 0; i < max; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    front++;
    visited[start] = 1;

    printf("BFS Traversal\n");
    while (rear >= front) {
        start = queue[front++];
        printf("%c -> ", start + 65);

        for (i = 0; i < max; i++) {
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int** adj, int* visited, int start, int max) {
    int stack[max], top = -1, i;

    for (i = 0; i < max; i++)
        visited[i] = 0;

    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal\n");
    while (top != -1) {
        start = stack[top--];
        printf("%c -> ", start + 65);

        for (i = 0; i < max; i++) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, option, max;
    char c;

    printf("Enter the number of vertices: ");
    scanf("%d", &max);

    int** adj = (int**)malloc(max * sizeof(int*));
    for (i = 0; i < max; i++) {
        adj[i] = (int*)malloc(max * sizeof(int));
    }

    int* visited = (int*)malloc(max * sizeof(int));

    do {
        printf("1. Enter values in  Adjacency Matrix\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("Enter the adjacency matrix (%d x %d):\n", max, max);
                for (i = 0; i < max; i++) {
                    for (j = 0; j < max; j++) {
                        scanf("%d", &adj[i][j]);
                    }
                }
                break;

            case 2:
                printf("Enter the starting character for BFS :");
                scanf("%c", &c);
                bfs(adj, visited, c - 65, max);
                break;

            case 3:
                printf("Enter the starting character for DFS ");
                scanf("%c", &c);
                dfs(adj, visited, c - 65, max);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (option != 4);


    for (i = 0; i < max; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return 0;
}
