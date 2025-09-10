// Kosaraju
//
// O(n + m)

int n;
vector<int> g[MAXN]; //(a vai para b)
vector<int> gi[MAXN]; // grafo reverso (b vai para a)
bool vis[MAXN];
stack<int> S;
int comp[MAXN]; //componente conexo de cada vertice
vector<int> condensed[MAXN];
set<int> sccs;
int num_scc = 0;
map<int, long long> grauEntrada;
map<int, long long> grauSaida;
long long sink, source;
 
void dfs(int k){
    vis[k] = true;
    for(auto i : g[k]){
        if(!vis[i]){
            dfs(i);
        }
    }
    S.push(k);
}
 
void scc(int k, int c){
    vis[k] = true;
    comp[k] = c;
    for(auto i : gi[k]){
        if(!vis[i]){
            scc(i, c);
        }
    }
}
 
void kosaraju(){
    for(int i = 0; i < n; i++) vis[i] = false;
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
 
    for(int i = 0; i < n; i++) vis[i] = false;
    while (S.size())
    {
        int u = S.top();
        S.pop();
        if(!vis[u]) {
            scc(u, u);
            num_scc++;
        }
    }
}
 
//grafo condensado apenas com as sccs
//analisa os graus de entrada e saida de cada sccs
void graph_condensed(){
 
    for (int i = 0; i < n; i++)
    {
        sccs.insert(comp[i]);
    }
    
    for (auto i : sccs)
    {
        grauEntrada[i] = 0;
        grauSaida[i] = 0;
    }
    
    //contar os sinks e sources
    sink = 0; source = 0;
 
    //contruir o grafo condensado
    for (int u = 0; u < n; u++)
    {
        for(auto v : g[u]){
            if(comp[u] != comp[v]){
                condensed[comp[u]].push_back(comp[v]);
                grauEntrada[comp[v]]++; grauSaida[comp[u]]++;
            }
        }
    }
 
    for (auto i : grauEntrada)
    {
        if(grauEntrada[i.first] == 0) source++;
    }
    for (auto i : grauSaida)
    {
        if(grauSaida[i.first] == 0) sink++;
    }
}
 