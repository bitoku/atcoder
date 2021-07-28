#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    vector<ll> dist(n, -1);
    vector<ll> cnt(n);
    dist[0] = 0;
    cnt[0] = 1;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        for (auto next: v[cur]) {
            if (dist[next] == cost + 1) {
                cnt[next] += cnt[cur];
                cnt[next] %= mod;
            } else if (dist[next] == -1 || dist[next] > cost + 1) {
                cnt[next] = cnt[cur];
                dist[next] = cost + 1;
                pq.push(make_pair(cost + 1, next));
            }
        }
    }
    cout << cnt[n-1] << endl;
}