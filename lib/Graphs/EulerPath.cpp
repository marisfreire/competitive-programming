template<bool directed=false> struct euler {
	int n;
	vector<vector<pair<int, int>>> g;
	vector<int> used;

	euler(int n_) : n(n_), g(n) {}
	void add(int a, int b) {
		int at = used.size();
		used.push_back(0);
		g[a].emplace_back(b, at);
		if (!directed) g[b].emplace_back(a, at);
	}

	pair<bool, vector<pair<int, int>>> get_path(int src) {
		if (!used.size()) return {true, {}};
		vector<int> beg(n, 0);
		for (int& i : used) i = 0;
		// {{vertice, anterior}, label}
		vector<pair<pair<int, int>, int>> ret, st = {{{src, -1}, -1}};
		while (st.size()) {
			int at = st.back().first.first;
			int& it = beg[at];
			while (it < g[at].size() and used[g[at][it].second]) it++;
			if (it == g[at].size()) {
				if (ret.size() and ret.back().first.second != at)
					return {false, {}};
				ret.push_back(st.back()), st.pop_back();
			} else {
				st.push_back({{g[at][it].first, at}, g[at][it].second});
				used[g[at][it].second] = 1;
			}
		}
		if (ret.size() != used.size()+1) return {false, {}};
		vector<pair<int, int>> ans;
		for (auto i : ret) ans.emplace_back(i.first.first, i.second);
		reverse(ans.begin(), ans.end());
		return {true, ans};
	}
	pair<bool, vector<pair<int, int>>> get_cycle() {
		if (!used.size()) return {true, {}};
		int src = 0;
		while (!g[src].size()) src++;
		auto ans = get_path(src);
		if (!ans.first or ans.second[0].first != ans.second.back().first)
			return {false, {}};
		ans.second[0].second = ans.second.back().second;
		ans.second.pop_back();
		return ans;
	}
};

/*LATEX_DESC_BEGIN***************************
	Euler Path / Euler Cycle
	Para declarar: euler<true> E(n) se for direcionado com N vertices
	As funções retornam um par
		- Booleano indica se há o path/cycle pedido
		- Vetor é formada de {vertice, id aresta para chegar no vertice}

	Se for get_path, na primeira posicao o id vai ser -1
	get_path(src) tenta achar um caminho ou ciclo euleriano, começando no src
#warning chamar para o src certo!
	Se achar um ciclo, o primeiro e o ultimo vertice seram src
	Se for um P3, um possível retorno seria [0, 1, 2, 0]
	get_cycle() acha um ciclo euleriano se o grafo for euleriano
	Se for um P3, um possível retorno seria [0,1,2]
	(Vértice inicial não se repete)

	O(n + m)
*****************************LATEX_DESC_END*/