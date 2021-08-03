#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/03

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

unordered_map<ll, ll> fact_memo;
ll mod_fact(ll x) {
    if (fact_memo.find(x) != fact_memo.end()) return fact_memo[x];
    if (x == 0) return 1;
    fact_memo[x] = x * mod_fact(x - 1) % mod;
    return fact_memo[x];
}

unordered_map<ll, ll> invfact_memo;
ll mod_invfact(ll x) {
    if (invfact_memo.find(x) != invfact_memo.end()) return invfact_memo[x];
    invfact_memo[x] = mod_pow(mod_fact(x), mod - 2);
    return invfact_memo[x];
}

ll mod_combi(ll n, ll r) {
    if (r < 0 || n < r) return 0;
    return mod_fact(n) * mod_invfact(r) % mod * (mod_invfact(n - r)) % mod;
}

int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        mod_fact(i);
    }
    for (int i = 1; i <= n; ++i) {
        ll result = 0;
        for (int j = 1; j <= (n + i - 1) / i; ++j) {
            result += mod_combi(n - (i - 1) * (j - 1), j);
            result %= mod;
        }
        cout << result << endl;
    }
}