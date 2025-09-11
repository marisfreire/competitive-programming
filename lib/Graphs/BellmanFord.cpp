
int n, m;
int d[MAX];
vector<pair<int, int>> edges; 
vector<int> weights;              

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[edges[j].second] > d[edges[j].first] + weights[j]) {
				if (i == n) return 1;

				d[edges[j].second] = d[edges[j].first] + weights[j];
			}
		}

	return 0;
}

/*LATEX_DESC_BEGIN***************************

	Bellman-Ford
	Calcula a menor distância entre (a) e todos os outros vértices
	Detecta ciclo negativo
	Retorna 1 se há ciclo negativo
	Não precisa representar o grafo
	Só armazenar as arestas

	O(n * m)
*****************************LATEX_DESC_END*/