#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Pair: {distance, node}
typedef pair<int, int> pii;

void dijkstra(int source, int N, vector<vector<pii>>& adj, vector<int>& dist) {
    // Min-heap priority queue
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        // Skip if we already found a better path
        if (d > dist[u]) continue;
        
        // Explore all neighbors
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    
    // (i) Accept number of nodes and edges
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> M;
    
    // Adjacency list: adj[u] = list of {v, weight}
    vector<vector<pii>> adj(N + 1);
    
    cout << "Enter each edge in the format: u v weight\n";
    cout << "(Nodes are numbered from 1 to " << N << ")\n";
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Undirected graph: add edge in both directions
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    
    // (ii) Compute shortest distances using Dijkstra's algorithm
    vector<int> dist(N + 1, INT_MAX);
    dijkstra(source, N, adj, dist);
    
    // (iii) Output distances in ascending order of node number
    cout << "\nShortest distances from source node " << source << ":\n";
    cout << "------------------------------------------\n";
    cout << "Node\tDistance\n";
    cout << "------------------------------------------\n";
    for (int i = 1; i <= N; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF (unreachable)\n";
        else
            cout << dist[i] << "\n";
    }
    
    return 0;
}