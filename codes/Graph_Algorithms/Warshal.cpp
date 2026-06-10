#include <bits/stdc++.h>
using namespace std;

void warshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> reach = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                reach[i][j] = reach[i][j] ||
                               (reach[i][k] && reach[k][j]);
            }
        }
    }

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int V = 4;

    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    warshall(graph, V);

    return 0;
}