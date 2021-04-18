#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        pq.push(p[i]);
    }
    ll result = 0;
    for (int i = 0; i < k; ++i) {
        auto [a, b] = pq.top(); pq.pop();
        result += a;
        pq.push(make_pair(a + b, b));
    }
    cout << result << endl;
}
