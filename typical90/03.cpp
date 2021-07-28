#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    deque<int> dq;
    dq.push_back(0);
    vector<int> depth(n, INT_MAX);
    depth[0] = 0;
    int d = 0;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        d = cur;
        for (auto next: v[cur]) {
            if (depth[next] < depth[cur]) continue;
            depth[next] = depth[cur] + 1;
            dq.push_back(next);
        }
    }
    dq.push_back(d);
    depth.clear();
    depth.resize(n, INT_MAX);
    depth[d] = 0;
    int result = 0;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        result = depth[cur];
        for (auto next: v[cur]) {
            if (depth[next] < depth[cur]) continue;
            depth[next] = depth[cur] + 1;
            dq.push_back(next);
        }
    }
    cout << result + 1 << endl;
}