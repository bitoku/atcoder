#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll x4 = n - a - b >= 0 ? (n - a - b + 2) * (n - a - b + 1) / 2 % mod : 0;
        ll x3 = 2 * x4 % mod;
        ll x2 = ((n - a + 1) * (n - b + 1) - x3) % mod;
        ll ans = (n - a + 1) * (n - b + 1) % mod;
        ans = ans * ans % mod - x2 * x2 % mod;
        cout << (ans + mod) % mod << endl;
    }
}