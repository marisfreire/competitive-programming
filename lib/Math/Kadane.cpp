
ll kadane(vector<ll> &arr) {
    ll answ = arr[0];
    ll maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        answ = max(answ, maxEnding);
    }

    return answ;
}

/*LATEX_DESC_BEGIN***************************
    Algoritmo de Kadane
    Consegue o max subarray sum
    O(N)  
*****************************LATEX_DESC_END*/
