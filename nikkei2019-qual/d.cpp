#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

void dfs(vector<vector<int>>& tree, vector<vector<int>>& revtree, vector<int>& ans, set<int>& used, int cur) {
    for (int x : tree[cur]) {
        if (any_of(revtree[x].begin(), revtree[x].end(), [&](int y) {return used.find(y) == used.end();})) {
            continue;
        }
        ans[x] = cur + 1;
        used.insert(x);
        dfs(tree, revtree, ans, used, x);
        used.erase(x);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> tree(n);
    vector<vector<int>> revtree(n);
    for (int i = 0; i < n - 1 + m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        revtree[b].push_back(a);
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (revtree[i].empty()) {
            root = i;
            break;
        }
    }
    vector<int> ans(n);
    set<int> used;
    used.insert(root);
    dfs(tree, revtree, ans, used, root);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
}