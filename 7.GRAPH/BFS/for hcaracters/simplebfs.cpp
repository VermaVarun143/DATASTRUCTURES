#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Add edge to the graph
void addEdge(map<char, vector<char>> &graph, char u, char v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // For undirected graph
}

// Perform BFS traversal
void BFS(map<char, vector<char>> &graph, char start) {
    map<char, int> visited; // Track visited vertices
    queue<char> q;

    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " ";

        for (char neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
    cout << endl;
}

int main() {
    int edges;
    char u, v, start;
    map<char, vector<char>> graph;

    cout << "Enter the number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    BFS(graph, start);

    return 0;
}
