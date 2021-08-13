#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(60, vector<ll>(100000));
    for (int i = 0; i < 100000; ++i) {
        ll t = i;
        ll temp = 0;
        while (t > 0) {
            temp += t % 10;
            t /= 10;
        }
        a[0][i] = (i + temp) % 100000;
    }
    for (int i = 1; i < 60; ++i) {
        for (int j = 0; j < 100000; ++j) {
            a[i][j] = a[i-1][a[i-1][j]];
        }
    }
    ll x = n;
    for (int i = 0; i < 60; ++i) {
        if (k & (1ll << i)) x = a[i][x];
    }
    cout << x << endl;
}