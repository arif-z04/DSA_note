#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [nbr, wt] : adj[node]) {
            if (dist[node] + wt < dist[nbr]) {
                dist[nbr] = dist[node] + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    // (node, weight)
    adj[0] = {{1, 10}, {2, 3}};
    adj[1] = {{2, 1}, {3, 2}};
    adj[2] = {{1, 4}, {3, 8}, {4, 2}};
    adj[3] = {{4, 7}};
    adj[4] = {{3, 9}};

    dijkstra(0, adj);

    return 0;
}