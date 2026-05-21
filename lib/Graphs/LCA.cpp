#include <bits/stdc++.h>
using namespace std;

/* LCA (Lowest Common Ancestor)
 * Encontra o ancestral comum mais próximo de dois vértices em uma árvore.
 * Complexidade: O(N log N) no build, O(1) por query.
 * Memória: O(N log N)
 * Requisitos:
 * - Grafo deve ser uma árvore (conexo e acíclico).
 * - Dependência: sparse-table/sparse-table.hpp
 * Métodos:
 * - lca(u, v): Retorna o LCA de u e v.
 * - dist(u, v): Retorna a distância entre u e v.
 * - is_ancestor(u, v): Verifica se u é ancestral de v.
 * - parent(u): Retorna o pai de u.
 */

template<typename NODE>
struct SparseTable {
    int N, K;
    vector<vector<NODE>> st;
    vector<int> lg;

    SparseTable() : N(0), K(0) {}

    SparseTable(const vector<NODE>& v) : N(v.size()) {
        if (N == 0) return;
        K = __lg(N);
        st.assign(K + 1, vector<NODE>(N));
        lg.assign(N + 1, 0);
        for (int i = 2; i <= N; i++) lg[i] = lg[i / 2] + 1;
        
        for (int i = 0; i < N; i++) st[0][i] = v[i]; 
        
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[j][i] = NODE::merge(st[j - 1][i],
                                       st[j - 1][i + (1 << (j - 1))]);
    }

    NODE query(int l, int r) {
        int j = lg[r - l + 1];
        return NODE::merge(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

struct LCANode {
    int dep, id;
    LCANode(int d = 1e9, int pos = -1) : dep(d), id(pos) {}
    
    static inline LCANode merge(const LCANode& l, const LCANode& r) {
        return l.dep < r.dep ? l : r;
    }
};

struct LCA {
    int N;
    vector<int> first, tour, d, p;
    SparseTable<LCANode> st;

    //(1-based indexing)
    LCA(int n, int root, const vector<vector<int>>& adj) 
        : N(n), first(n + 1), d(n + 1), p(n + 1, -1), st(vector<LCANode>()) {
        
        vector<LCANode> euler_nodes; 
        tour.reserve(2 * n + 5);
        euler_nodes.reserve(2 * n + 5);

        auto dfs = [&](auto self, int u, int parent_id, int dep) -> void {
            p[u] = parent_id;
            d[u] = dep;
            first[u] = euler_nodes.size();
            
            tour.push_back(u);
            euler_nodes.push_back(LCANode(dep, u));
            
            for (int next_node : adj[u]) { 
                if (next_node == parent_id) continue;
                self(self, next_node, u, dep + 1);
                
                tour.push_back(u);
                euler_nodes.push_back(LCANode(dep, u));
            }
        };

        dfs(dfs, root, -1, 0);
        
        st = SparseTable<LCANode>(euler_nodes);
    }

    int parent(int u) {
        return p[u];
    }

    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        return st.query(l, r).id; 
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }

    bool is_ancestor(int u, int v) {
        return lca(u, v) == u;
    }
};