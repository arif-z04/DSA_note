#include <bits/stdc++.h>
using namespace std;

void prim(int V, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }

}


int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};

    prim(V, adj);

    return 0;
}