#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
ll d[MAX];
int parent[MAX];

vector<pair<int, int>> edges; 
vector<ll> weights;
vector<int> cycle;

bool bellman_ford() {
	// dist = 0 em todos => detecta ciclo em qualquer componente
	for (int i = 0; i < n; i++) {
		d[i] = 0;
		parent[i] = -1;
	}
	int x = -1;

	for (int i = 0; i < n; i++) {
		x = -1;

		for (int j = 0; j < m; j++) {
			int u = edges[j].first;
			int v = edges[j].second;
			ll w = weights[j];

			if (d[v] > d[u] + w) {
				d[v] = max(-INF, d[u] + w);
				parent[v] = u;
				x = v;
			}
		}
	}

	// sem ciclo negativo
	if (x == -1) return false;

	// entra dentro do ciclo
	for (int i = 0; i < n; i++) x = parent[x];
    int cur = x;

	do {
		cycle.push_back(cur);
		cur = parent[cur];
	}
	while (cur != x); 
    cycle.push_back(x);
	reverse(cycle.begin(), cycle.end());

	return true;
}

/*LATEX_DESC_BEGIN***************************

	USO:
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w;
            u--; v--;

			edges.push_back({u, v});
			weights.push_back(w);
		}

		if (bellman_ford()) {
			cout << "YES\n";
			for (auto x : cycle)
				cout << x + 1 << " ";
		}
		else {
			cout << "NO\n";
		}

*****************************LATEX_DESC_END*/