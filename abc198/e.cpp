#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

multiset<int> cset;
vector<int> good;

void solve(vector<vector<int>>& tree, vector<int>& c, int cur, int par) {
    if (cset.find(c[cur]) == cset.end()) {
        good.push_back(cur);
    }
    cset.insert(c[cur]);
    for (const auto next: tree[cur]) {
        if (next == par) continue;
        solve(tree, c, next, cur);
    }
    auto it = cset.find(c[cur]);
    cset.erase(it);
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve(tree, c, 0, -1);
    sort(good.begin(), good.end());
    for (auto x: good) {
        cout << x + 1 << endl;
    }
}
