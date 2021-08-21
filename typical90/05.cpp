#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, b;
    int k;
    cin >> n >> b >> k;
    vector<ll> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    vector<vector<map<ll, ll>>> dbl(60, vector<map<ll, ll>>(b));
    for (auto x: c) {
        for (int j = 0; j < b; ++j) {
            ll y = (j * 10 + x) % b;
            dbl[0][j][y]++;
        }
    }
    for (int i = 1; i < 60; ++i) {
        for (int j = 0; j < b; ++j) {
            for (auto [y, x]: dbl[i-1][j]) {
                for (auto [y2, x2]: dbl[i-1][y]) {
                    dbl[i][j][y2] += x * x2 % mod;
                    dbl[i][j][y2] %= mod;
                }
            }
        }
    }
    map<ll, ll> mp;
    for (auto x: c) {
        mp[x % b]++;
    }
    n--;
    for (int i = 0; i < 60; ++i) {
        if (n & (1ll << i)) {
            map<ll, ll> nmp;
            for (auto [y, x]: mp) {
                for (auto [y2, x2]: dbl[i][y]) {
                    nmp[y2] += x * x2 % mod;
                    nmp[y2] %= mod;
                }
            }
            mp = nmp;
        }
    }
    cout << mp[0] << endl;
}