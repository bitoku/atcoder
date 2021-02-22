#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    vector<vector<int>> edges(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> path(n+1);
    path[a]++;
    set<int> pos = {a};
    while (path[b] == 0 && !pos.empty()) {
        set<int> next;
        vector<int> next_path(n+1);
        for (const auto& from : pos) {
            for (const auto& to : edges[from]) {
                next_path[to] += path[from];
                next_path[to] %= mod;
                next.insert(to);
            }
        }
        path = next_path;
        pos = next;
    }
    cout << path[b] << endl;
}
