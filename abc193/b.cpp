#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll m = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll a, p, x;
        cin >> a >> p >> x;
        if (x - a > 0) m = min(m, p);
    }
    if (m == LONG_LONG_MAX) cout << -1 << endl;
    else cout << m << endl;
}
