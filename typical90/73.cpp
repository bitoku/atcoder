#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/17

vector<int> cha;

tuple<ll, ll, ll> dfs(vector<vector<int>>& v, int cur, int par) {
    ll a = 1, b = 1, c = 1;
    for (auto x: v[cur]) {
        if (x == par) continue;
        auto [pa, pb, pc] = dfs(v, x, cur);
        if (cha[cur] == 0) {
            a *= pa + pc;
            a %= mod;
        } else {
            b *= pb + pc;
            b %= mod;
        }
        c *= pa + pb + 2 * pc;
        c %= mod;
    }
    if (cha[cur] == 0) {
        c = (c - a + mod) % mod;
        return {a, 0, c};
    } else {
        c = (c - b + mod) % mod;
        return {0, b, c};
    }
}

int main() {
    ll n;
    cin >> n;
    cha.resize(n);
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'a') cha[i] = 0;
        else cha[i] = 1;
    }
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto [_a, _b, c] = dfs(v, 0, -1);
    cout << c << endl;
}