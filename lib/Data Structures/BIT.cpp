#include <bits/stdc++.h>
using namespace std;

struct BIT {
	vector<int> bit;
	int N;

	BIT(){}
	
    BIT(const vector<int>& a) {
        N = a.size();
        bit.assign(N + 1, 0);

        for (int i = 1; i <= N; ++i)
            bit[i] = a[i - 1];

        for (int i = 1; i <= N; ++i) {
            int j = i + (i & -i);
            if (j <= N)
                bit[j] += bit[i];
        }
    }
    
	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
};

/*LATEX_DESC_BEGIN***************************

    BIT - Fenwick Tree

    Complexidade:
    - Build: O(n)
    - Single Update: O(log n)
    - Query: O(log n)

*****************************LATEX_DESC_END*/