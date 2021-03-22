#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> idx(n - 1);
    iota(idx.begin(), idx.end(), 1);
    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    ll result = 0;
    do {
        ll temp = 0;
        int pos = 0;
        for (int i = 0; i < n - 1; ++i) {
            temp += dist[pos][idx[i]];
            pos = idx[i];
        }
        temp += dist[idx[n-2]][0];
        if (temp == k) result++;
    } while (next_permutation(idx.begin(), idx.end()));
    cout << result << endl;
}
