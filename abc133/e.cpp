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

ll fact_range(ll n, ll k) {
    if (n - k < 0) return 0;
    return fact[n] * fact_inv[n-k] % mod;
}

int n, k;

ll dfs(vector<vector<int>>& edge, int cur, int par) {
    ll result = 1;
    if (par == -1) {
        result *= fact_range(k, edge[cur].size() + 1);
    } else {
        result *= fact_range(k - 2, edge[cur].size() - 1);
    }
    for (const auto& x : edge[cur]) {
        if (x == par) continue;
        result *= dfs(edge, x, cur);
        result %= mod;
    }
    return result;
}

int main() {
    cin >> n >> k;
    vector<vector<int>> edge(n);
    init_combi(200000, mod);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cout << dfs(edge, 0, -1) << endl;
}
