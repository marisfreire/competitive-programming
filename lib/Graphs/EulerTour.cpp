#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

bool visitados[MAXN];

void EulerTour(int u, vector<vector<int>>& adj, vector<int>& euler){
    euler.push_back(u);
    visitados[u] = true;

    for(auto v : adj[u]){
        if(!visitados[v]){
            EulerTour(v, adj, euler);
            euler.push_back(u);
        }
    }
}
/*LATEX_DESC_BEGIN***************************
	Euler Tour
    Lineariza um grafo
    Verificar a ancestralida u é ancestral de v se in[u] <= in[v] <= out[u]
    
*****************************LATEX_DESC_END*/