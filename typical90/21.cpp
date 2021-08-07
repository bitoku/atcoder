#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/05

void dfs1(vector<vector<int>>& edge, vector<int>& order, vector<bool>& visit, int cur) {
    static int k;
    if (visit[cur]) return;
    visit[cur] = true;
    for (auto x: edge[cur]) {
        if (visit[x]) continue;
        dfs1(edge, order, visit, x);
    }
    order[k++] = cur;
}

void dfs2(vector<vector<int>>& redge, vector<bool>& visit, vector<int>& labels, int label, int cur) {
    if (visit[cur]) return;
    visit[cur] = true;
    labels[cur] = label;
    for (auto x: redge[cur]) {
        if (visit[x]) continue;
        dfs2(redge, visit, labels, label, x);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n), redge(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        redge[b].push_back(a);
    }
    vector<int> order(n);
    vector<bool> visit(n);
    for (int i = 0; i < n; ++i) {
        if (visit[i]) continue;
        dfs1(edge, order, visit, i);
    }
    visit.clear();
    visit.resize(n);
    reverse(order.begin(), order.end());
    vector<int> labels(n, -1);
    int label = 0;
    for (auto x: order) {
        if (labels[x] != -1) continue;
        dfs2(redge, visit, labels, label, x);
        label++;
    }
    map<int, ll> mp;
    for (int i = 0; i < n; ++i) {
        mp[labels[i]]++;
    }
    ll result = 0;
    for (auto [_, x]: mp) {
        result += x * (x-1) / 2;
    }
    cout << result << endl;
}