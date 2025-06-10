#include <iostream>
#include <queue>
using namespace std;

// Initialize adjacency matrix
void initializeGraph(int** &adjMatrix, int vertices) {
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices] {0};
    }
}

// Free memory of adjacency matrix
void deleteGraph(int** &adjMatrix, int vertices) {
    for (int i = 0; i < vertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

// Add edge to the graph
void addEdge(int** adjMatrix, int u, int v, int vertices) {
    if (u >= vertices || v >= vertices || u < 0 || v < 0) {
        cout << "Invalid edge!" << endl;
        return;
    }
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For an undirected graph
}

// Perform BFS traversal
void BFS(int** adjMatrix, int vertices, int start) {
    if (start >= vertices || start < 0) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }
    int* visited = new int[vertices] {0}; // Track visited vertices
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[node][i] && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
    delete[] visited;
}

int main() {
    int vertices, edges, u, v, start;
    int** adjMatrix;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    initializeGraph(adjMatrix, vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(adjMatrix, u, v, vertices);
    }

    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    BFS(adjMatrix, vertices, start);

    deleteGraph(adjMatrix, vertices);

    return 0;
}
