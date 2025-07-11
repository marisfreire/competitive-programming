#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 9987123

vector<ll> fact(1e6, -1);

void pre(){
    fact[0] = 1;
    for(ll i = 1; i < fact.size(); i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

ll fexp(ll a, ll b){
    ll ans = -1;

    while(b){
        if(b & 1) ans = (ans * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }

    return ans;
}

ll inv(ll a, ll p){
    return fexp(a, p -2);
}

ll comb(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p)) % p) * inv(fact[n-k], p) % p;
}

/*LATEX_DESC_BEGIN***************************
    Combinação modular
    Inverso modular
    Exponenciação rápida (O (Log P ) - p: potência)
    O(N) fatorial
*****************************LATEX_DESC_END*/