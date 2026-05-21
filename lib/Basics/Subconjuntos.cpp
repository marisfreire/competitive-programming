int main() {
    int n; vector<int> v(n); 

    // 1 << n = 2^n subconjuntos
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {

            // se o i-ésimo bit está ligado
            if (mask & (1 << i)) {
                subset.push_back(v[i]);
            }
        }

        // imprime o subconjunto atual
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

/*LATEX_DESC_BEGIN************************

Bitmask - Geração de Subconjuntos
Quando usar: n <= 20 ~ 22

Complexidade: O(n * 2^n)

***************************LATEX_DESC_END*/