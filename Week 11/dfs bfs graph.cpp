#include <iostream>
#include <limits>
using namespace std;

const int MAX = 100;
const int INF = numeric_limits<int>::max(); // Representation of no edge

class Graph {
private:
    int graph[MAX][MAX]; // Adjacency matrix
    int n;               // Number of nodes

public:
    Graph(int nodes) {
        n = nodes;
        // Initialize matrix with INF (no edge)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = INF;
    }

    void addEdge(int u, int v, int weight) {
        if (u >= 0 && v >= 0 && u < n && v < n) {
            graph[u][v] = weight; // Directed edge with weight
        }
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix (INF = no edge):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == INF)
                    cout << "INF ";
                else
                    cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFSUtil(int node, bool visited[]) {
        cout << node << " ";
        visited[node] = true;
        for (int i = 0; i < n; i++) {
            if (graph[node][i] != INF && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[MAX] = { false };
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        bool visited[MAX] = { false };
        int queue[MAX], front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "\nBFS Traversal: ";

        while (front < rear) {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < n; i++) {
                if (graph[node][i] != INF && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    void Dijkstra(int start) {
        int dist[MAX];
        bool visited[MAX];

        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[start] = 0;

        for (int count = 0; count < n - 1; count++) {
            int minDist = INF, u = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] <= minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "\nShortest distances from node " << start << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)
                cout << "Node " << i << ": INF" << endl;
            else
                cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    Graph g(nodes);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges in format (u v weight):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.displayMatrix();

    int start;
    cout << "\nEnter starting node for DFS and BFS: ";
    cin >> start;
    g.DFS(start);
    g.BFS(start);

    cout << "\nEnter starting node for Dijkstra: ";
    cin >> start;
    g.Dijkstra(start);

    return 0;
}
