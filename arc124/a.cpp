#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll> vv(n);
    for (int i = 0; i < k; ++i) {
        char c;
        ll x;
        cin >> c >> x;
        x--;
        if (c == 'L') {
            v[x] = 1;
            for (int j = x + 1; j < n; ++j) {
                vv[j]++;
            }
        } else {
            v[x] = 1;
            for (int j = 0; j < x; ++j) {
                vv[j]++;
            }
        }
    }
    ll result = 1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) continue;
        result *= vv[i];
        result %= mod;
    }
    cout << result << endl;
}