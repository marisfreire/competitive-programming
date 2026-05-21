#include <bits/stdc++.h>
using namespace std;

struct Bridges {
    int n;
    vector<vector<int>> g;
    vector<pair<int,int>> bridges;

    Bridges(int n) : n(n), g(n) {}

    Bridges(const vector<vector<int>>& adj)
        : n(adj.size()), g(adj) { build(); }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build() {
        vector<int> num(n, -1), low(n);
        int timer = 0;

        function<void(int,int)> dfs = [&](int v, int par) {
            low[v] = num[v] = timer++;
            for (int u : g[v]) {
                if (num[u] == -1) {
                    dfs(u, v);
                    low[v] = min(low[v], low[u]);
                    if (low[u] > num[v]) bridges.push_back({v, u});
                } else if (u != par) {
                    low[v] = min(low[v], num[u]);
                }
            }
        };

        for (int i = 0; i < n; i++)
            if (num[i] == -1) dfs(i, -1);
    }
};