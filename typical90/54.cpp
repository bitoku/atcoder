#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Path {
    int to;
    int c;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Path>> a(n+m);
    for (int i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int r;
            cin >> r;
            r--;
            a[n+i].push_back({r, 1});
            a[r].push_back({n+i, 0});
        }
    }
    vector<int> b(n+m, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (b[cur] != -1) continue;
        b[cur] = cost;
        for (auto x: a[cur]) {
            if (b[x.to] != -1) continue;
            pq.push(make_pair(cost + x.c, x.to));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << endl;
    }
}