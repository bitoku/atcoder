#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 09/20

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
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p.begin(), p.end());
    // k 以上の距離の点が存在する → true
    auto func = [&](ll k) {
        int l = 0;
        ll ymn = INT_MAX, ymx = 0;
        for (int r = 0; r < n; ++r) {
            auto [x, y] = p[r];
            while (r - l > 0 && p[l].first <= x - k) {
                ymn = min(ymn, p[l].second);
                ymx = max(ymx, p[l].second);
                l++;
            }
            if (ymn <= y - k || y + k <= ymx) return true;
        }
        return false;
    };
    cout << binsearch(INT_MAX, 0, func) << endl;
}