
int n;
vector<int> g[MAXN]; 
vector<int> gi[MAXN]; 
bool vis[MAXN];
stack<int> S;
int comp[MAXN]; 
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
    
    sink = 0; source = 0;
 
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
 

/*LATEX_DESC_BEGIN***************************
    Kosaraju (Grafos fortemente conexos)

    g é o grafo (a vai para b)
    gi é o grafo reverso (b vai para a)

    comp é o componente conexo de cada vértice

    graph_condensed() grafo condensado apenas com as sccs
    analisa os graus de entrada e saídas de cadas sccs


    O(m + n)
*****************************LATEX_DESC_END*/