#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first >> p[i].second;
        }
        sort(p.begin(), p.end());
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        ll current = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            pq.push({p[i].second, p[i].first});
            while (i + 1 < n && p[i+1].first == p[i].first) {
                i++;
                pq.push({p[i].second, p[i].first});
            }
            while (!pq.empty() && (i + 1 == n || current + 1 < p[i+1].first)) {
                if (current + 1 > pq.top().first) {
                    ok = false;
                    break;
                }
                current = max(pq.top().second, current+1);
                pq.pop();
            }
            if (!ok) break;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}