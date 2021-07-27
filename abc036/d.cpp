#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

pair<ll, ll> dfs(vector<vector<int>>& v, int cur, int par) {
    if (v[cur].size() == 1 && v[cur][0] == par) {
        return make_pair(1, 1);
    }
    ll white = 1;
    ll black = 1;
    for (auto next: v[cur]) {
        if (next == par) continue;
        pair<ll, ll> p = dfs(v, next, cur);
        black *= p.first;
        black %= mod;
        white *= (p.first + p.second);
        white %= mod;
    }
    return make_pair(white, black);
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pair<ll, ll> p = dfs(v, 0, -1);
    cout << (p.first + p.second) % mod << endl;
}