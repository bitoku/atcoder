#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    map<pair<ll, ll>, bool> ship;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        ship[make_pair(a, b)] = true;
    }
    for (int i = 2; i < n; ++i) {
        if (ship[make_pair(1, i)] && ship[make_pair(i, n)]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
