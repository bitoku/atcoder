#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    vector<set<int>> e(n);
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        b[u] += a[v];
        b[v] += a[u];
        e[u].insert(v);
        e[v].insert(u);
    }
    multiset<pair<ll, int>> c;
    for (int i = 0; i < n; ++i) {
        c.insert(make_pair(b[i], i));
    }
    ll result = 0;
    while (!c.empty()) {
        auto it = c.begin();
        result = max(result, it->first);
        int x = it->second;
        c.erase(it);
        for (auto i : e[x]) {
            e[i].erase(x);
            auto itt = c.find(make_pair(b[i], i));
            b[i] -= a[x];
            c.erase(itt);
            c.insert(make_pair(b[i], i));
        }
    }
    cout << result << endl;
}