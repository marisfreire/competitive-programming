vector<int> vis; 
vector<vector<pair<int, int>>> adj; 
 
ll prim(int atual) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh; 
    mh.push({0, atual}); 
 
    ll custo = 0; 
 
    while (!mh.empty()) {
        auto [c, u] = mh.top(); mh.pop(); 
 
        if (!vis[u]) {
            vis[u] = true;
            custo = custo + c; 
 
            for (auto [v, peso] : adj[u]) {
                if (!vis[v]) {
                    mh.push({peso, v}); 
                }
            }
        }
    }
 
    return custo; 
}


/*LATEX_DESC_BEGIN************************

Prim - Minimum Spanning Tree
Algoritmo para encontrar a Árvore Geradora Mínima (MST)

Estratégia:
-> Expande a árvore sempre pegando a menor aresta disponível

Complexidade: O(E log V)

E = número de arestas; V = número de vértices

***************************LATEX_DESC_END*/
