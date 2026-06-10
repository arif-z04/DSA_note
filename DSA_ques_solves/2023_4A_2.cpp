#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Dijkstra Algorithm
void dijkstra(int src, int N, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(N + 1, INF);

    // Min-heap (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Output in ascending order of node number
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 1; i <= N; i++) {
        cout << "Node " << i << " : ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int N, M;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> M;

    vector<vector<pair<int,int>>> adj(N + 1);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(src, N, adj);

    return 0;
}