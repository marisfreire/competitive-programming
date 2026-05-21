const int INF = 1e18; 
using vi = vector<int>; 
using pii = pair<int,int>; 
vector<vector<pii>> grafo; 

vi dijkstra(int s, int n){
    vi dist (n, INF); 
    priority_queue<pii, vector<pii>, greater<pii>> fila;
	fila.push({0, s});
	dist[s] = 0;
    
	while(!fila.empty()) {
        auto [d, u] = fila.top();
		fila.pop();

		if(d > dist[u]) continue;

		for(auto [c, v] : grafo[u]) {
			if( dist[v] > dist[u] + c ) {
				dist[v] = dist[u] + c;
				fila.push({dist[v], v});
			}
		}
	}

	return dist;
}

/*LATEX_DESC_BEGIN************************

Dijkstra - Shortest Paths from Source
Calcula a menor distancia de um vertice s
para todos os outros vertices do grafo.
Funciona apenas com pesos >= 0.

Complexity: O((N + M) log N)

grafo[u] = {c, v}
u -> vertice atual
v -> destino
c -> custo da aresta

priority_queue ordena por menor distancia: {distancia, vertice}

***************************LATEX_DESC_END*/