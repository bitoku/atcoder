#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> book(n, vector<int>(m));
    vector<ll> price(n);
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
        for (int j = 0; j < m; ++j) {
            cin >> book[i][j];
        }
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < (1 << n); ++i) {
        vector<ll> algo(m);
        ll p = 0;
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            p += price[j];
            for (int k = 0; k < m; ++k) {
                algo[k] += book[j][k];
            }
        }
        if (all_of(algo.begin(), algo.end(), [x](int a) {return a >= x;})) {
            result = min(result, p);
        }
    }
    if (result == LONG_LONG_MAX) cout << -1 << endl;
    else cout << result << endl;
}
