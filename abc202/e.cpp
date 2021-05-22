#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

vector<int> in;
vector<int> out;
map<int, vector<int>> depths;
int t = 0;

void dfs(vector<vector<int>> &edges, int cur, int par, int depth) {
    in[cur] = t++;
    depths[depth].push_back(in[cur]);
    for (int x: edges[cur]) {
        if (x == par) continue;
        dfs(edges, x, cur, depth+1);
    }
    out[cur] = t++;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> edges(n);
    in.resize(n);
    out.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        p--;
        edges[i].push_back(p);
        edges[p].push_back(i);
    }
    dfs(edges, 0, -1, 0);
    ll q;
    cin >> q;
    for (auto& [k, v]: depths) {
        sort(v.begin(), v.end());
    }
    for (int i = 0; i < q; ++i) {
        int u, d;
        cin >> u >> d;
        u--;
        auto left = lower_bound(depths[d].begin(), depths[d].end(), in[u]);
        auto right = upper_bound(depths[d].begin(), depths[d].end(), out[u]);
        cout << max(0, (int)distance(left, right)) << endl;
    }
}