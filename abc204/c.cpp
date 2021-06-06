#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

set<ll> done;

void dfs(vector<vector<ll>>& edges, ll cur) {
    if (done.find(cur) != done.end()) return;
    done.insert(cur);
    for (auto next: edges[cur]) {
        dfs(edges, next);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(n);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        dfs(edges, i);
        result += done.size();
        done.clear();
    }
    cout << result << endl;
}