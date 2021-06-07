#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

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

vector<ll> memo;

ll dfs(ll n, ll m) {
    if (m == 0) return 1;
    if (memo[m] != 0) return memo[m];
    ll k = m % 4;
    if (k == 1 || k == 3) return 0;
    ll ret = 0;
    for (int i = 0; 4 * i + k <= n && 4 * i + k <= m; ++i) {
        ret += dfs(n, (m - (4 * i + k)) / 2) * mod_combi(n, 4 * i + k) % mod;
        ret %= mod;
    }
    memo[m] = ret;
    return ret;
}

int main() {
    ll n, m;
    cin >> n >> m;
    memo.resize(m+1, 0);
    cout << dfs(n, m) << endl;
}