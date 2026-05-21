vector<vector<int>> adj; 
vector<int> estados; 
stack<int> st; 

void toposort(int atual, bool& ciclo) {
    estados[atual] = 1; 

    for (auto vizinho : adj[atual]) {
        if (estados[vizinho] == 0) {
            toposort(vizinho, ciclo); 
        } else if (estados[vizinho] == 1) {
            // há ciclo
            ciclo = true; 
            return; 
        }
    }

    estados[atual] = 2; 
    st.push(atual); 
}

/*LATEX_DESC_BEGIN************************

Topological Sort (DFS)

Estados:
0 = não visitado
1 = em processamento
2 = finalizado

Complexidade: O(V + E)

***************************LATEX_DESC_END*/