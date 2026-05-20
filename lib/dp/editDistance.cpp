#include <bits/stdc++.h>
using namespace std;

long long editDistance(const std::string& s1, const std::string& s2, 
                              long long a, long long b, long long c, long long d) {
    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<long long>> memo(n + 1, std::vector<long long>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            
            //caso base: se a segunda string vazia, apenas deleções
            if (j == 0) {
                memo[i][j] = i * b;
            }
            //caso base: se a primeira string vazia, apenas inserções
            else if (i == 0) {
                memo[i][j] = j * a;
            }
            //caracteres iguais, custo 0
            else if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1];
            }
            //caracteres diferentes, calcula o menor custo operacional
            else {
                long long op_insercao = memo[i][j - 1] + a;
                long long op_delecao = memo[i - 1][j] + b;
                long long op_substituicao = memo[i - 1][j - 1] + c;

                memo[i][j] = std::min({op_insercao, op_delecao, op_substituicao});

                //verifica se a Transposição é possível e se ela é mais barata
                if (i >= 2 && j >= 2 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1]) {
                    long long op_transposicao = memo[i - 2][j - 2] + d;
                    memo[i][j] = std::min(memo[i][j], op_transposicao);
                }
            }
        }
    }

    return memo[n][m];
}