#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (int)1e9 + 7;

vector<long long> fact, fact_inv, inv;

template< typename T >
void init_combi(size_t size, const T mod) {
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
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    init_combi(N, MOD);
    sort(A.begin(), A.end());
    ll ans = 0;
    for (ll i = 0; i < N - K + 1; ++i) {
        ll n = N - i - 1;
        ll c = mod_combi(n, K - 1, MOD);
        ans = (ans - (A[i] * c) % MOD ) % MOD;
        ans = (ans + (A[A.size() - 1 - i] * c) % MOD ) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
