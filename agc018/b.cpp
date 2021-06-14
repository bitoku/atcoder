#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    set<ll> done;
    vector<int> idx(n);
    ll result = LONG_LONG_MAX;
    while (done.size() < m) {
        map<ll, ll> mp;
        for (int i = 0; i < n; ++i) {
            int &j = idx[i];
            while (done.find(v[i][j]) != done.end()) {
                j++;
            }
            mp[v[i][j]]++;
        }
        ll mx = 0;
        ll mxi = 0;
        for (auto [a, b]: mp) {
            if (b > mx) {
                mxi = a;
                mx = b;
            }
        }
        result = min(mx, result);
        done.insert(mxi);
    }
    cout << result << endl;
}