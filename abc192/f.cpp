#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 07/01

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = n; i >= 1; --i) {
        vector<vector<ll>> v(n, vector<ll>(n));
        for (int j = 0; j < n; ++j) {
            for (int k = max(i - 2, j - 1); k >= 0; --k) {
                for (int l = 0; l < n; ++l) {
                    if (v[k][l]) {
                        v[k+1][(l + a[j]) % i] = max(v[k+1][(l + a[j]) % i], v[k][l] + a[j]);
                    }
                }
            }
            v[0][a[j] % i] = max(v[0][a[j] % i], a[j]);
        }
        if (v[i - 1][x % i]) {
            result = min((x - v[i - 1][x % i]) / i, result);
        }
    }
    cout << result << endl;
}