#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

map<ll, ll> factorize(ll n) {
    map<ll, ll> m;
    ll lim = (ll)sqrt(n) + 10;
    while (n % 2 == 0) {
        n >>= 1;
        m[2]++;
    }
    for (int i = 3; i < lim; i += 2) {
        while (n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    if (n > 1) m[n]++;
    return m;
}

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> ff = factorize(m);
    init_combi(n + 10000, mod);
    ll result = 1;
    for (const auto [_, x]: ff) {
        result = (result * mod_combi(n - 1 + x, x, mod)) % mod;
    }
    cout << result << endl;
}
