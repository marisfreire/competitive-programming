#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define INF 100000000
#define pii pair<int,int>

vector<vi> adj;
vector<vi> capacidade; // capacidade[u][v] = cap. da aresta u -> v
vi pai;

vector<bool> vis;
bool bfs(int source, int sink){
 
	fill(pai.begin(), pai.end(), -1);
	fill(vis.begin(), vis.end(), false);
	queue<int> q;
	q.push(source);
 
	vis[source] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int v : adj[u]){
			int c = capacidade[u][v];
			if(c <= 0 || pai[v] != -1 || vis[v]) continue;
			vis[v] = 1;
			pai[v] = u;
			q.push(v);
		}
	}
	return pai[sink] != -1;
}
 
ll maxflow(int source, int sink){
	ll flow = 0;
 
	while(bfs(source,sink)){
		int u = sink;
		int curr_flow = INF;
 
		while(u != source){
			curr_flow = min(curr_flow, capacidade[pai[u]][u]);
			u = pai[u];
		}
 
		u = sink;
 
		while(u != source){
			// augment
			capacidade[pai[u]][u] -= curr_flow;
			capacidade[u][pai[u]] += curr_flow;
			u = pai[u];
		}
 
		flow += curr_flow;
	}
 
	return flow;
}


/*LATEX_DESC_BEGIN************************

MCMF Simplificado 
Achar o MinCut é rodar a bfs mais uma vez pra checar quem não é mais reachable (Tem capacidade menor que 0)
MinCut == Flow = Max_flow
***************************LATEX_DESC_END*/
