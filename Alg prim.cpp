#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 7
#define INF 1e9

void prim(vector<vector<int>>& g) {
    vector<bool> usado(N, false);
    vector<int> costo(N, INF);
    vector<int> padre(N, -1);

    costo[0] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cola;
    cola.push({0, 0}); 

    while (!cola.empty()) {
        int actual = cola.top().second;
        cola.pop();

        if (usado[actual]) continue;
        usado[actual] = true;

        for (int v = 0; v < N; v++) {
            if (g[actual][v] && !usado[v] && g[actual][v] < costo[v]) {
                costo[v] = g[actual][v];
                padre[v] = actual;
                cola.push({costo[v], v});
            }
        }
    }

    int total = 0;
    cout << "Arista\tPeso\n";
    for (int i = 1; i < N; i++) {
        char a = 'A' + padre[i];
        char b = 'A' + i;
        cout << a << " - " << b << "\t" << g[i][padre[i]] << "\n";
        total += g[i][padre[i]];
    }

    cout << "Peso total del MST: " << total << "\n";
}

int main() {
    vector<vector<int>> grafo = {
        { 0, 7, 0, 5, 0, 0, 0 }, 
        { 7, 0, 8, 9, 7, 0, 0 }, 
        { 0, 8, 0, 0, 5, 0, 0 }, 
        { 5, 9, 0, 0,15, 6, 0 }, 
        { 0, 7, 5,15, 0, 8, 9 }, 
        { 0, 0, 0, 6, 8, 0,11 }, 
        { 0, 0, 0, 0, 9,11, 0 }  
    };

    prim(grafo);
    return 0;
}
