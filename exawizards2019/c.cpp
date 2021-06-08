#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

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
    ll n, Q;
    cin >> n >> Q;
    string s;
    cin >> s;
    vector<pair<char, int>> q(Q);
    for (int i = 0; i < Q; ++i) {
        char t, d;
        cin >> t >> d;
        q[i].first = t;
        if (d == 'L') q[i].second = -1;
        else q[i].second = 1;
    }
    auto func1 = [&](int x) {
        if (x < 0) return true;
        if (x >= n) return false;
        for (auto [t, d]: q) {
            if (s[x] == t) x += d;
            if (x < 0) return true;
            if (x >= n) return false;
        }
        return false;
    };
    auto func2 = [&](int x) {
        if (x < 0) return false;
        if (x >= n) return true;
        for (auto [t, d]: q) {
            if (s[x] == t) x += d;
            if (x < 0) return false;
            if (x >= n) return true;
        }
        return false;
    };
    ll left = binsearch(n, -1, func1) + 1;
    ll right = n - binsearch(-1, n, func2);
    cout << n - (left + right) << endl;

}