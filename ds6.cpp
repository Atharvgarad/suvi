#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
 
    for (int i = 0; i < (int)graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next])
            DFS(next, graph, visited);
    }
}
 
void BFS(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
 
    visited[start] = true;
    q.push(start);
 
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
 
        for (int i = 0; i < (int)graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
 
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;
 
    if (vertices <= 0 || edges < 0) {
        cout << "Invalid graph size.\n";
        return 0;
    }
 
    vector<vector<int>> graph(vertices);
 
    cout << "Enter edges using vertex numbers from 0 to "
         << vertices - 1 << ":\n";
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || a >= vertices || b < 0 || b >= vertices) {
            cout << "Invalid vertex number.\n";
            return 0;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    if (start < 0 || start >= vertices) {
        cout << "Invalid starting vertex.\n";
        return 0;
    }
 
    vector<bool> visited(vertices, false);
    cout << "DFS traversal: ";
    DFS(start, graph, visited);
    cout << endl;
 
    cout << "BFS traversal: ";
    BFS(start, graph);
    cout << endl;
 
    return 0;
}
