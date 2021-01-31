#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int dp[1<<17][17];
int n, m;
int k;

ll dfs(int s, int v, const vector<vector<ll>> &dist) {
    if (dp[s][v] != 0) return dp[s][v];
    if (s == 0) return 0;

    ll result = INT_MAX;
    for (int i = 0; i < k; ++i) {
        if ((s & 1 << i) == 0) continue;
        result = min(result, dfs(s - (1 << i), i, dist) + dist[i][v]);
    }
    dp[s][v] = result;
    return result;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> pairable(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pairable[a].push_back(b);
        pairable[b].push_back(a);
    }
    cin >> k;
    vector<int> c(k);
    vector<vector<ll>> dist(k, vector<ll>(k));
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < k; ++i) {
        deque<pair<int, int>> dq;
        vector<bool> done(n);
        dq.emplace_back(c[i], 0);
        done[c[i]] = true;
        while (!dq.empty()) {
            auto curpair = dq.front(); dq.pop_front();
            int cur = curpair.first;
            auto it = find(c.begin(), c.end(), cur);
            if (it != c.end()) {
                int x = distance(c.begin(), it);
                dist[i][x] = curpair.second;
            }
            for (int & node : pairable[cur]) {
                if (done[node]) continue;
                done[node] = true;
                dq.emplace_back(node, curpair.second+1);
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            if (dist[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    ll result = INT_MAX;
    for (int i = 0; i < k; ++i) {
        result = min(result, dfs((1 << k) - 1, i, dist));
    }
    cout << result+1 << endl;
}
