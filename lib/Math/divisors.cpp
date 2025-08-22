#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> get_divisors(int n ){
    vector<int> divisors;

    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != n/i) divisors.push_back(n/i);
        }
    }
    return divisors;
}

/*LATEX_DESC_BEGIN***************************
    get_divisors(n) -- O(sqrt(N))
*****************************LATEX_DESC_END*/