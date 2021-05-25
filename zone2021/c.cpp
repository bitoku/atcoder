#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n;
    cin >> n;
    multimap<ll, ll> m;
    vector<tuple<ll, ll, ll, ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v[i] = make_tuple(a, b, c, d, e);
    }
    auto func = [v, n](ll x) {
        map<tuple<ll, ll, ll, ll, ll>, int> s;
        for (int i = 0; i < n; ++i) {
            ll a = get<0>(v[i]) >= x ? 1 : 0;
            ll b = get<1>(v[i]) >= x ? 1 : 0;
            ll c = get<2>(v[i]) >= x ? 1 : 0;
            ll d = get<3>(v[i]) >= x ? 1 : 0;
            ll e = get<4>(v[i]) >= x ? 1 : 0;
            s[make_tuple(a, b, c, d, e)]++;
        }
        for (auto& [t1, a] : s) {
            for (auto& [t2, b] : s) {
                for (auto& [t3, c] : s) {
                    if (t1 == t2 && t2 == t3 && a < 3) continue;
                    else if (t1 == t2 && a < 2) continue;
                    else if (t2 == t3 && b < 2) continue;
                    else if (t3 == t1 && c < 2) continue;
                    if (min({
                                    max({get<0>(t1), get<0>(t2), get<0>(t3)}),
                                    max({get<1>(t1), get<1>(t2), get<1>(t3)}),
                                    max({get<2>(t1), get<2>(t2), get<2>(t3)}),
                                    max({get<3>(t1), get<3>(t2), get<3>(t3)}),
                                    max({get<4>(t1), get<4>(t2), get<4>(t3)}),
                            })) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    cout << binsearch(1000000001, 0, func) << endl;
}