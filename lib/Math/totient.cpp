#include <bits/stdc++.h>
using namespace std;

// Totiente
//
// O(sqrt(n))

int tot(int n) {
	int ret = n;

	for (int i = 2; i*i <= n; i++) if (n % i == 0) {
		while (n % i == 0) n /= i;
		ret -= ret / i;
	}
	if (n > 1) ret -= ret / n;

	return ret;
}

/*LATEX_DESC_BEGIN***************************
   Totiente de Euler - Conta quantos números de 1 até n são corpimos de n
   

   Complexidade:
   O(sqrt(n))
*****************************LATEX_DESC_END*/