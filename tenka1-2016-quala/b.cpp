#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll result = 0;
unordered_map<ll, ll> mp;

ll dfs(vector<vector<ll>>& children, ll cur) {
    if (cur == 0) {
        ll ret = 0;
        for (const auto next: children[cur]) {
            ret += dfs(children, next);
        }
        return ret;
    }
    if (children[cur].empty()) {
        return mp[cur];
    }
    vector<ll> k(children[cur].size());
    ll mn = LONG_LONG_MAX;
    for (int i = 0; i < children[cur].size(); ++i) {
        k[i] = dfs(children, children[cur][i]);
        mn = min(mn, k[i]);
    }
    for (int i = 0; i < children[cur].size(); ++i) {
        result += k[i] - mn;
    }
    return mn;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> children(n);
    vector<ll> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        children[p[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        ll b, c;
        cin >> b >> c;
        mp[b] = c;
    }
    result += dfs(children, 0);
    cout << result << endl;
}