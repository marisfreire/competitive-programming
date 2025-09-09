// Time Complexity: O(arr.size())
ll kadane(vector<ll> &arr) { // Max Subarray Sum
    ll answ = arr[0];
    ll maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        answ = max(answ, maxEnding);
    }

    return answ;
}