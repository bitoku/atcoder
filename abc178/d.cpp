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
    ll s;
    cin >> s;
    ll result = 0;
    init_combi(2005, mod);
    for (ll i = 1; i <= s / 3; ++i) {
        result += mod_combi(s - i * 3 + i - 1, i - 1, mod);
        result %= mod;
    }
    cout << result << endl;
}
