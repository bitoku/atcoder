#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

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
    long long N, M, K;
    cin >> N >> M >> K;
    long long ans = 0;
    init_combi(N, mod);
    for (long long k = 0; k <= K; ++k) {
        long long s = mod_combi(N-1, k, mod);
        s = (s * M) % mod;
        s = (s * mod_pow(M-1, N-k-1, mod)) % mod;
        ans = (ans + s) % mod;
    }
    cout << ans << endl;
}
