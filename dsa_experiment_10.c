#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of cities/nodes

int adj_matrix[MAX][MAX];
int num_nodes;

// --- Stack implementation for DFS (simple array) ---
int stack[MAX];
int top = -1;

void push_s(int item) { stack[++top] = item; }
int pop_s() { return stack[top--]; }
int is_stack_empty() { return top == -1; }

// --- Queue implementation for BFS (simple array) ---
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) { 
    if (rear == MAX - 1) return; // Overflow check
    if (front == -1) front = 0;
    queue[++rear] = item; 
}
int dequeue() { 
    if (front == -1) return -1; // Underflow check
    int item = queue[front];
    if (front == rear) { front = -1; rear = -1; }
    else front++;
    return item;
}
int is_queue_empty() { return front == -1; }


// --- 1. Create Graph (Adjacency Matrix) ---
void create_graph() {
    int i, j, edge;
    
    printf("Enter the number of cities (nodes, MAX=%d): ", MAX);
    scanf("%d", &num_nodes);
    
    if (num_nodes > MAX) {
        printf("Error: Number of nodes exceeds MAX size.\n");
        num_nodes = 0;
        return;
    }
    
    printf("Enter the Adjacency Matrix (1 for edge, 0 for no edge):\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            printf("Edge from %d to %d: ", i, j);
            scanf("%d", &edge);
            adj_matrix[i][j] = edge;
        }
    }
}

// --- 2. DFS Traversal for Reachable Nodes ---
void dfs(int start_node) {
    int visited[MAX] = {0};
    int current_node;
    
    // Reset stack
    top = -1;
    
    push_s(start_node);
    visited[start_node] = 1;
    
    printf("DFS Reachable Nodes: ");
    
    while (!is_stack_empty()) {
        current_node = pop_s();
        printf("%d ", current_node);
        
        // Find adjacent unvisited nodes
        for (int i = 0; i < num_nodes; i++) {
            if (adj_matrix[current_node][i] == 1 && visited[i] == 0) {
                push_s(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// --- 3. BFS Traversal for Reachable Nodes ---
void bfs(int start_node) {
    int visited[MAX] = {0};
    int current_node;

    // Reset queue
    front = -1; rear = -1; 
    
    enqueue(start_node);
    visited[start_node] = 1;
    
    printf("BFS Reachable Nodes: ");
    
    while (!is_queue_empty()) {
        current_node = dequeue();
        printf("%d ", current_node);
        
        // Find adjacent unvisited nodes
        for (int i = 0; i < num_nodes; i++) {
            if (adj_matrix[current_node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int choice, start_node;

    while (1) {
        printf("\n--- Graph Operations Menu ---\n");
        printf("1. Create Graph (Adjacency Matrix)\n");
        printf("2. Find Reachable Nodes using DFS\n");
        printf("3. Find Reachable Nodes using BFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Clearing buffer.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                create_graph();
                break;
            case 2:
            case 3:
                if (num_nodes == 0) {
                    printf("Please create the graph first (Option 1).\n");
                    break;
                }
                printf("Enter the starting city/node (0 to %d): ", num_nodes - 1);
                scanf("%d", &start_node);
                if (start_node < 0 || start_node >= num_nodes) {
                    printf("Invalid start node.\n");
                    break;
                }
                
                if (choice == 2) {
                    dfs(start_node);
                } else {
                    bfs(start_node);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
