#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> buf(2000001);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll k = a[i] + b[j];
            if (buf[k] != make_pair(0, 0)) {
                cout << i << ' ' << j << ' ' << buf[k].first << ' ' << buf[k].second << endl;
                return 0;
            }
            buf[k] = make_pair(i, j);
        }
    }
    cout << -1 << endl;
}