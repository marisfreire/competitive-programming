#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int divi[MAX];
vector<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

void crivo_mobius(ll lim) {
    mobius[1] = 1;
    for (int i = 2; i <= lim; i++) {
        if (!divi[i]) {
            divi[i] = i;
            primes.push_back(i);
            mobius[i] = -1; // primo → μ = -1
        }
        for (int p : primes) {
            if (p > divi[i] || 1LL * i * p > lim) break;
            divi[i*p] = p;
            if (i % p == 0) {
                mobius[i*p] = 0; // quadrado → μ = 0
                break;
            } else {
                mobius[i*p] = -mobius[i];
            }
        }
    }
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

/*LATEX_DESC_BEGIN***************************
   Sieve of Eratosthenes - Encontra o maior divisor primo
   Fact -> Fatora um número <= limite, sai ordenada
   Crivo calcula a lista de primos
   
   Crivo_mobius
		- 1 se n=1
		- 0 se n tem algum fator primo ao quadrado
		- (-1)^k se n é produto de k primos distintos

   A função fact adiciona o número 1 se vc tentar fatorar o 1.
   Complexidade:
   crivo - O(n log(logN))
   fact - O(log(n))
*****************************LATEX_DESC_END*/