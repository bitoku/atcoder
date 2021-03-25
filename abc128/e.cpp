#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct stop{
    ll s;
    ll t;
    ll x;
};

int main() {
    ll n, q;
    cin >> n >> q;
    vector<stop> stops;
    map<ll, ll> road;
    for (int i = 0; i < n; ++i) {
        cin >> stops[i].s >> stops[i].t >> stops[i].x;
        road[stops[i].s] = LONG_LONG_MAX;
        road[stops[i].t] = LONG_LONG_MAX;
    }
    vector<ll> d(q);
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
        road[d[i]] = LONG_LONG_MAX;
    }
    multiset<int> s;
    for (auto& [a, b] : d) {
        if (b > 0) {
            s.insert(b);
        } else {
            auto it = s.find(-b);
            s.erase(it);
        }
        b = *min_element(s.begin(), s.end());
    }

}
