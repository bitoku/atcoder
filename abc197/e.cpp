#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        y--;
        a[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    ll x = 0, y = 0;
    ll xx = 0, yy = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].empty()) continue;
        ll nxx = min(abs(x - a[i].back()) + xx,
                 abs(y - a[i].back()) + yy) + a[i].back() - a[i].front();
        ll nyy = min(abs(x - a[i].front()) + xx,
                 abs(y - a[i].front()) + yy) + a[i].back() - a[i].front();
        x = a[i].front();
        y = a[i].back();
        xx = nxx;
        yy = nyy;
    }
    cout << min(xx + abs(x), yy + abs(y)) << endl;
}