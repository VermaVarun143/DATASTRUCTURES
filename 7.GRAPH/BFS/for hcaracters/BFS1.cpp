#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

// Add edge to the graph
void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // For undirected graph
}

// Convert character to index
int charToIndex(char c) {
    return tolower(c) - 'a'; // Maps 'a' or 'A' to 0, 'b' or 'B' to 1, etc.
}

// Convert index to character
char indexToChar(int index) {
    return 'a' + index; // Maps 0 to 'a', 1 to 'b', etc.
}

// Perform BFS traversal
void BFS(vector<int> graph[], int totalVertices, char start) {
    int visited[totalVertices] = {0};
    queue<int> q;

    int startIndex = charToIndex(start);
    if (startIndex < 0 || startIndex >= totalVertices) {
        cout << "Invalid starting vertex!" << endl;
        return;
    }

    q.push(startIndex);
    visited[startIndex] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << indexToChar(node) << " ";

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 0) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
    cout << endl;
}

int main() {
    int edges, totalVertices = 26; // Assuming vertices are 'a' to 'z'
    vector<int> graph[totalVertices];

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        char u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;

        int uIndex = charToIndex(u);
        int vIndex = charToIndex(v);

        if (uIndex >= 0 && uIndex < totalVertices && vIndex >= 0 && vIndex < totalVertices) {
            addEdge(graph, uIndex, vIndex);
        } else {
            cout << "Invalid edge: " << u << " - " << v << endl;
        }
    }

    char start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    BFS(graph, totalVertices, start);

    return 0;
}
