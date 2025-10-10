#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// -------------------------------
// Template Graph Class
// -------------------------------
template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> edgeList;

    // Add an edge between u and v
    // direction = 0 → Undirected
    // direction = 1 → Directed
    void addEdge(T u, T v, bool direction) {
        if (direction) {
            // Directed edge
            edgeList[u].push_back(v);
        } else {
            // Undirected edge
            edgeList[u].push_back(v);
            edgeList[v].push_back(u);
        }
        print();
    }

    // Print adjacency list
    void print() {
        cout << "\nAdjacency List:\n";
        for (auto& node : edgeList) {
            cout << node.first << " -> { ";
            for (auto& neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << "}\n";
        }
        cout << endl;
    }

    // -------------------------------
    // Breadth-First Search (BFS)
    // -------------------------------
    void bfs(T src) {
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        cout << "\nBFS Traversal: ";
        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            for (auto& neighbor : edgeList[frontNode]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }

    // -------------------------------
    // Depth-First Search (DFS)
    // -------------------------------
    void dfs(T src, unordered_map<T, bool>& visited) {
        visited[src] = true;
        cout << src << " ";

        for (auto& neighbor : edgeList[src]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
};

// -------------------------------
// Main Function
// -------------------------------
int main() {
    Graph<char> g;
    unordered_map<char, bool> visited;

    g.addEdge('a', 'b', 1);
    g.addEdge('a', 'c', 1);
    g.addEdge('c', 'd', 1);
    g.addEdge('c', 'e', 1);
    g.addEdge('d', 'e', 1);
    g.addEdge('e', 'f', 1);

    cout << "\nDFS Traversal: ";
    g.dfs('a', visited);

    // Uncomment to test BFS
    // g.bfs('a');

    // Uncomment to see adjacency list
    // g.print();

    return 0;
}
