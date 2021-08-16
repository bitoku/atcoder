#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/16

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> v(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i][j];
        }
    }
    ll result = 0;
    for (int i = 1; i < (1 << h); ++i) {
        ll temp = 0;
        ll y = 0;
        map<ll, int> mp;
        for (int j = 0; j < h; ++j) {
            if (i & (1 << j)) y++;
        }
        for (int j = 0; j < w; ++j) {
            ll x = -1;
            bool ok = true;
            for (int k = 0; k < h; ++k) {
                if ((i & (1 << k)) == 0) continue;
                if (x == -1) x = v[k][j];
                else if (x != v[k][j]) ok = false;
            }
            if (ok) mp[x]++;
        }
        for (auto [_, t]: mp) {
            result = max(result, t * y);
        }
    }
    cout << result << endl;
}