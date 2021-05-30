#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, map<ll, bool>> black;
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        black[x][y] = true;
    }
    set<ll> ys;
    ys.insert(n);
    for (auto it = black.begin(); it != black.end(); ++it) {
        set<ll> next;
        for (auto [y, ok]: it->second) {
            if (y - 1 >= 0 && ys.find(y-1) != ys.end()) {
                next.insert(y);
            }
            if (y+1 <= 2 * n && ys.find(y + 1) != ys.end()) {
                next.insert(y);
            }
        }
        for (auto [y, ok]: it->second) {
            if (ys.find(y) != ys.end()) {
                ys.erase(y);
            }
        }
        for (auto x: next) {
            ys.insert(x);
        }
        if (ys.empty()) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ys.size() << endl;
}