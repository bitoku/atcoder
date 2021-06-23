#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> plus;
    vector<ll> minus;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a < 0) minus.push_back(a);
        else plus.push_back(a);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());
    vector<pair<ll, ll>> ops;
    ll m = 0;
    if (plus.empty()) {
        m = minus.back();
        for (int i = 0; i < minus.size() - 1; ++i) {
            ops.emplace_back(m, minus[i]);
            m = m - minus[i];
        }
    } else if (minus.empty()) {
        m = plus.front();
        for (int i = 1; i < plus.size() - 1; ++i) {
            ops.emplace_back(m, plus[i]);
            m = m - plus[i];
        }
        ops.emplace_back(plus.back(), m);
        m = plus.back() - m;

    } else {
        if (plus.size() == 1) {
            m = plus.front();
            for (int i = 0; i < minus.size(); ++i) {
                ops.emplace_back(m, minus[i]);
                m = m - minus[i];
            }
        } else {
            m = minus.front();
            for (int i = 0; i < plus.size() - 1; ++i) {
                ops.emplace_back(m, plus[i]);
                m = m - plus[i];
            }
            ops.emplace_back(plus.back(), m);
            m = plus.back() - m;
            for (int i = 1; i < minus.size(); ++i) {
                ops.emplace_back(m, minus[i]);
                m = m - minus[i];
            }
        }
    }
    cout << m << endl;
    for (auto [a, b]: ops) {
        cout << a << ' ' << b << endl;
    }
}