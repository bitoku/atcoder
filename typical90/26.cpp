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
    vector<int> depth(n, -1);
    deque<int> dq;
    dq.push_back(0);
    depth[0] = 0;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        for (auto x: v[cur]) {
            if (depth[x] != -1) continue;
            depth[x] = depth[cur] + 1;
            dq.push_back(x);
        }
    }
    vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
        if (depth[i] % 2 == 0) even.push_back(i+1);
        if (depth[i] % 2 == 1) odd.push_back(i+1);
    }
    vector<int>& vec = even;
    if (even.size() < n / 2) {
        vec = odd;
    }
    cout << vec[0];
    for (int i = 1; i < n / 2; ++i) {
        cout << ' ' << vec[i];
    }
    cout << endl;
}