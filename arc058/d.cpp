#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<long long> fact, fact_inv, inv;

template< typename T >
void init_combi(size_t size, const T mod) {
    size += 1;
    fact.resize(size);
    fact_inv.resize(size);
    inv.resize(size);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 1; i < size-1; i++) {
        fact[i+1] = fact[i] * (i + 1) % mod;
        inv[i+1] = mod - inv[mod % (i+1)] * (mod / (i+1)) % mod;
        fact_inv[i+1] = fact_inv[i] * inv[i+1] % mod;
    }
}

template< typename T >
T mod_combi(T n, T k, T mod) {
    // return kCn % mod
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    init_combi(200010, mod);
    ll result = 0;
    for (ll i = b; i < w; ++i) {
        ll route = mod_combi((h - a - 1) + i, i, mod) * mod_combi((w - i - 1) + a - 1, a - 1, mod) % mod;
        result += route;
        result %= mod;
    }
    cout << result << endl;
}
