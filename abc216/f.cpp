#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

// TODO: 09/21

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });
    vector<vector<ll>> c(n+1, vector<ll>(5001));
    vector<vector<ll>> d(n+1, vector<ll>(5001));
    c[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int k = idx[i];
        for (int j = 0; j <= 5000; ++j) {
            c[i+1][j] = (c[i+1][j] + c[i][j]) % mod;
            if (j + b[k] > 5000) continue;
            c[i+1][j + b[k]] = (c[i+1][j + b[k]] + c[i][j]) % mod;
            d[i+1][j + b[k]] = (d[i+1][j + b[k]] + c[i][j]) % mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 5000; ++j) {
            d[i][j+1] += d[i][j];
            d[i][j+1] %= mod;
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        int k = idx[i];
        result += d[i+1][a[k]];
        result %= mod;
    }
    cout << result << endl;
}