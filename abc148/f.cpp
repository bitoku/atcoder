#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int n;

int tree_height(const vector<vector<int>> & tree, int cur, int par, vector<int> & height, vector<int> & parent) {
    parent[cur] = par;
    for (const auto& next : tree[cur]) {
        if (next == par) continue;
        height[cur] = max(height[cur], tree_height(tree, next, cur, height, parent) + 1);
    }
    return height[cur];
}

int main() {
    int tak, aok;
    cin >> n >> tak >> aok;
    vector<vector<int>> tree(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> depth(n + 1, -1);
    deque<int> dq = {aok};
    depth[aok] = 0;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        for (const auto & next : tree[cur]) {
            if (depth[next] != -1) continue;
            depth[next] = depth[cur] + 1;
            dq.push_back(next);
        }
    }
    vector<int> height(n + 1);
    vector<int> parent(n+1);
    tree_height(tree, aok, -1, height, parent);
    int result = 0;
    int cur = tak;
    while (depth[cur] - depth[aok] > depth[tak] - depth[cur]) {
        result = max(result, depth[cur] - depth[aok] + height[cur] - 1);
        cur = parent[cur];
    }
    cout << result << endl;
}
