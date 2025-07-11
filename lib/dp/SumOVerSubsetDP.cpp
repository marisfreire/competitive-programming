#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sos_dp_sub(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}


vector<ll> sos_dp_sup(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if (~mask>>i&1) f[mask] += f[mask^(1<<i)];
	return f;
}
/*LATEX_DESC_BEGIN***************************
    SOS DP [nohash]
    
    Soma de sub-conjunto e de super-conjunto
    O(n 2^n)

*****************************LATEX_DESC_END*/