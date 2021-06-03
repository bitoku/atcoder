#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }
    ll xx = 0;
    for (int i = 1; i < n; ++i) {
        xx += (x[i] - x[i-1]) * i % mod * (n - i) % mod;
        xx %= mod;
    }
    ll yy = 0;
    for (int i = 0; i < m; ++i) {
        yy += (y[i] - y[i-1]) * i % mod * (m - i) % mod;
        yy %= mod;
    }
    cout << xx * yy % mod << endl;

}