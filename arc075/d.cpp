#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    // ngは常に条件を満たさない, okは常に条件を満たす
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll m = 0;
    vector<ll> monster(n);
    for (int i = 0; i < n; ++i) {
        cin >> monster[i];
        m = max(m, monster[i]);
    }
    auto func = [monster, a, b, n](ll x) {
        ll center = 0;
        for (int i = 0; i < n; ++i) {
            center += (max(0ll, monster[i] - b * x) + a - b - 1) / (a - b);
        }
        return center <= x;
    };
    cout << binsearch(0, m, func) << endl;
}
