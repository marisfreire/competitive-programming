vector<int> compress(vector<int> &v) {
    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    vector<int> ans;

    for(int x : v) {
        ans.push_back(
            lower_bound(comp.begin(), comp.end(), x) - comp.begin()
        );
    }

    return ans;
}

int main() {
    vector<int> v = {100, 500, 100, 1000, -20};
    vector<int> c = compress(v);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " -> " << c[i] << "\n";
    }
}

/*LATEX_DESC_BEGIN

    Compressão de coordenadas

    Objetivo:
    -> transformar valores grandes
       em índices pequenos

    Complexidade:
    -> O(n log n)

LATEX_DESC_END*/