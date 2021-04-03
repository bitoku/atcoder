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
    vector<stop> stops(n);
    map<ll, vector<ll>> road;
    for (int i = 0; i < n; ++i) {
        cin >> stops[i].s >> stops[i].t >> stops[i].x;
        road[stops[i].s - stops[i].x].push_back(stops[i].x);
        road[stops[i].t - stops[i].x].push_back(-stops[i].x);
    }
    multiset<ll> s;
    map<ll, ll> roadmin;
    for (auto [k, vx]: road) {
        for (long long x : vx) {
            if (x > 0) {
                s.insert(x);
                if (s.empty()) {
                    roadmin[k] = LONG_LONG_MAX;
                } else {
                    roadmin[k] = *(s.begin());
                }
            } else {
                auto it = s.find(-x);
                s.erase(it);
                if (s.empty()) {
                    roadmin[k] = LONG_LONG_MAX;
                } else {
                    roadmin[k] = *(s.begin());
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        ll d;
        cin >> d;
        auto it = roadmin.upper_bound(d);
        if (it == roadmin.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            if ((*it).second == LONG_LONG_MAX) {
                cout << -1 << endl;
            } else {
                cout << (*it).second << endl;
            }
        }
    }
}
