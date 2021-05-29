#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    vector<pair<ll, int>> x(n);
    vector<pair<ll, int>> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
        p[i] = make_pair(x[i].first, y[i].first);
    }
    set<int> use;
    sort(x.begin(), x.end());
    use.insert(x[0].second);
    use.insert(x[1].second);
    use.insert(x[n-2].second);
    use.insert(x[n-1].second);
    sort(y.begin(), y.end());
    use.insert(y[0].second);
    use.insert(y[1].second);
    use.insert(y[n-2].second);
    use.insert(y[n-1].second);
    vector<ll> dist;
    for (int a: use) {
        for (int b: use) {
            if (a >= b) continue;
            dist.push_back(max(abs(p[a].first - p[b].first), abs(p[a].second - p[b].second)));
        }
    }
    sort(dist.begin(), dist.end(), greater<>());
    cout << dist[1] << endl;
}