#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) {
        return w < other.w;
    }
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            mstWeight += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total MST Weight = " << mstWeight << endl;
}


int main() {
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(V, edges);

    return 0;
}