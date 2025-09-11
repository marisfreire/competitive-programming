
int n;
int d[MAX][MAX];

bool floyd_warshall() {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0) return 1;

	return 0;
}

/*LATEX_DESC_BEGIN***************************

	Floyd-Warshall
	Encontra o menor caminho entre todo par de vértices e detecta ciclo negativo
	Returna 1 se há ciclo negativo
	d[i][i] deve ser 0
	para i != j, d[i][j] deve ser w se há uma aresta (i, j) de w, INF caso contrário
	O(n³)
*****************************LATEX_DESC_END*/