#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    multiset<pair<ll, ll>> s;
    for (int i = 0; i < n; ++i) {
        ll w, p;
        cin >> w;
        cin >> p;
        s.insert(make_pair(p, w));
    }
    ll pw = 0;
    ll ww = 0;
    for (int i = 0; i < k; ++i) {
        ld temp = 0;
        ll ppp = 0;
        ll www = 0;
        for (auto [p, w]: s) {
            if (temp < (ld)(pw + p * w) / (ww + w)) {
                temp = (ld)(pw + p * w) / (ww + w);
                ppp = p;
                www = w;
            }
        }
        auto it = s.find(make_pair(ppp, www));
        pw += ppp * www;
        ww += www;
        s.erase(it);
    }
    cout << setprecision(12) << (ld)pw / ww << endl;
}