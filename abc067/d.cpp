#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int n;
set<int> route;
int cnt[100000];

int dfs(vector<vector<int>>& tree, int cur, int par) {
    int result = 1;
    for (const auto x : tree[cur]) {
        if (x == par) continue;
        result += dfs(tree, x, cur);
    }
    cnt[cur] = result;
    if (route.find(cur) != route.end()) return 0;
    return result;
}

int main() {
    cin >> n;
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<int> prev(n, -1);
    deque<int> dq = {0};
    prev[0] = 0;
    while (!dq.empty()) {
        int x = dq.front(); dq.pop_front();
        for (const auto y : e[x]) {
            if (prev[y] != -1) continue;
            prev[y] = x;
            if (y == n-1) break;
            dq.push_back(y);
        }
        if (prev[n-1] != -1) break;
    }
    int x = n - 1;
    deque<int> path;
    route.insert(x);
    path.push_front(x);
    while (prev[x] != x) {
        x = prev[x];
        route.insert(x);
        path.push_front(x);
    }
    dfs(e, 0, -1);
    int f = 0, s = 0;
    for (int i = 0; i < path.size() / 2; ++i) {
        f += cnt[path[i]] - 1;
        s += cnt[path[path.size() - i - 1]] - 1;
    }
    if (path.size() % 2 == 1) {
        f += cnt[path[path.size() / 2]] - 1;
        s--;
    }
    if (f > s) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}
