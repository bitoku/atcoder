#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(60, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i];
        a[0][i]--;
    }
    for (int i = 1; i < 60; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = a[i-1][a[i-1][j]];
        }
    }
    int pos = 0;
    for (ll i = 0; (1ll << i) <= k; ++i) {
        if (k & (1ll << i)) pos = a[i][pos];
    }
    cout << pos+1 << endl;
}
