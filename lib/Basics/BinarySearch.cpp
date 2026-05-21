void bs() {
    vector<int> v; 
    long long l = 0;
    long long r = LLONG_MAX;
    int target; 

    while(l <= r) {
        long long m = l + (r - l) / 2;

        if(v[m] == target) {
            break;
        } else if(v[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}

/*LATEX_DESC_BEGIN

    Busca binária sem overflow
    -> l + (r - l) / 2

    Complexidade:
    -> O(log n)

LATEX_DESC_END*/