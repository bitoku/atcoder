#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string first, last;
    cin >> first >> last;
    ll n;
    cin >> n;
    vector<string> s(n+2);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    s[0] = first;
    s[n+1] = last;
    if (first == last) {
        cout << 0 << endl;
        cout << first << endl;
        cout << last << endl;
        return 0;
    }
    vector<vector<int>> edges(n+2);
    for (int i = 0; i < n+2; ++i) {
        for (int j = i + 1; j < n+2; ++j) {
            if (s[i] == s[j]) continue;
            for (int k = 0; k < first.size(); ++k) {
                char t = s[i][k];
                s[i][k] = s[j][k];
                if (s[i] == s[j]) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                    s[i][k] = t;
                    break;
                }
                s[i][k] = t;
            }
        }
    }
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.push(make_tuple(0, 0, 0));
    vector<ll> dist(n+2, -1);
    vector<int> prev(n+2);
    while (!pq.empty()) {
        auto [c, i, p] = pq.top(); pq.pop();
        if (dist[i] != -1) continue;
        dist[i] = c;
        prev[i] = p;
        if (i == n+1) break;
        for (auto j: edges[i]) {
            if (dist[j] != -1) continue;
            pq.push(make_tuple(c+1, j, i));
        }
    }
    if (dist[n+1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    deque<int> result;
    int x = prev[n+1];
    while (x > 0) {
        result.push_front(x);
        x = prev[x];
    }
    cout << dist[n+1] - 1 << endl;
    cout << first << endl;
    for (auto i: result) {
        cout << s[i] << endl;
    }
    cout << last << endl;
}