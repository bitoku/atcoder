#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> p(n);
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].second >> p[i].first;
        pq.push(p[i]);
    }
    ll result = 0;
    for (int i = 0; i < k; ++i) {
        auto [b, a] = pq.top(); pq.pop();
        result += b;
        if (a > 0) {
            pq.push(make_pair(a - b, 0));
        }
    }
    cout << result << endl;
}