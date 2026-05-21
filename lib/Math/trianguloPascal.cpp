#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; 

//O(N ao quadrado)
//Pré-computa os coeficientes binomiais (combinações) usando o Triângulo de Pascal.
//De quantas formas posso escolher k elementos distintos a partir de um conjunto de n elementos?
//limite O valor máximo de 'n' que você deseja calcular (geralmente determinado por 'maxi').

std::vector<std::vector<int>> precompute_combinacoes(int limite) {

    std::vector<std::vector<int>> tabela_pascal(limite + 1, std::vector<int>(limite + 1, 0));

    for (int i = 0; i <= limite; i++) {
        tabela_pascal[i][0] = 1;
    }

    for (int i = 1; i <= limite; i++) {
        for (int j = 1; j <= i; j++) {
            tabela_pascal[i][j] = (tabela_pascal[i - 1][j - 1] + tabela_pascal[i - 1][j]) % MOD;
        }
    }

    return tabela_pascal;
}