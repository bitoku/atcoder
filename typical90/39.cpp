#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<ll> nodes;

ll dfs(vector<vector<int>>& v, int cur, int par) {
    ll result = 1;
    for (auto x: v[cur]) {
        if (x == par) continue;
        result += dfs(v, x, cur);
    }
    nodes[cur] = result;
    return result;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n);
    nodes.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(v, 0, -1);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (auto x: v[i]) {
            int mn = min(nodes[i], nodes[x]);
            result += mn * (n - mn);
        }
    }
    cout << result / 2 << endl;
}