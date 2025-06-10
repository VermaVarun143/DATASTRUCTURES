#include <iostream>
#include <queue>
#include <map>
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
void addEdge(int** adjMatrix, map<char, int> &vertexMap, char u, char v) {
    if (vertexMap.find(u) == vertexMap.end() || vertexMap.find(v) == vertexMap.end()) {
        cout << "Invalid edge!" << endl;
        return;
    }
    int uIndex = vertexMap[u];
    int vIndex = vertexMap[v];
    adjMatrix[uIndex][vIndex] = 1;
    adjMatrix[vIndex][uIndex] = 1; // For an undirected graph
}

// Perform BFS traversal
void BFS(int** adjMatrix, map<char, int> &vertexMap, map<int, char> &reverseMap, char start) {
    if (vertexMap.find(start) == vertexMap.end()) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }
    int vertices = vertexMap.size();
    int* visited = new int[vertices] {0}; // Track visited vertices
    queue<int> q;

    q.push(vertexMap[start]);
    visited[vertexMap[start]] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << reverseMap[node] << " ";

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
    int vertices, edges;
    char u, v, start;
    int** adjMatrix;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    initializeGraph(adjMatrix, vertices);

    map<char, int> vertexMap;       // Maps vertex label to index
    map<int, char> reverseMap;     // Maps index back to vertex label

    cout << "Enter vertex labels: ";
    for (int i = 0; i < vertices; i++) {
        char vertex;
        cin >> vertex;
        vertexMap[vertex] = i;
        reverseMap[i] = vertex;
    }

    cout << "Enter the number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(adjMatrix, vertexMap, u, v);
    }

    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    BFS(adjMatrix, vertexMap, reverseMap, start);

    deleteGraph(adjMatrix, vertices);

    return 0;
}
