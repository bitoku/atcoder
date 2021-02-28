#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

vector<long long> fact, fact_inv, inv;

template< typename T >
void init_combi(size_t size) {
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
T mod_combi(T n, T k) {
    // return kCn % mod
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;
    init_combi<ll>(1000);
    if (n > k) {
        cout << mod_combi(k + n - 1, k) << endl;
        return 0;
    }
    ll x = k % n;
    cout << mod_combi(n, x) << endl;
}
