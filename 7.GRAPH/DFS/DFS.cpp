#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;

// Add edge to the graph
void addEdge(map<char, vector<char>> &graph, char u, char v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // For undirected graph
}

// Perform DFS traversal
void DFS(map<char, vector<char>> &graph, char start) {
    map<char, int> visited; // Track visited vertices
    stack<char> s;

    s.push(start);
    visited[start] = 1;

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        char node = s.top();
        s.pop();
        cout << node << " ";

        for (char neighbor : graph[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
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

    cout << "Enter starting vertex for DFS: ";
    cin >> start;
    DFS(graph, start);

    return 0;
}
