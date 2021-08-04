#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    ld l, x, y;
    cin >> l >> x >> y;
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ld e;
        cin >> e;
        ld ey = -l / 2 * sin(2 * M_PI * e / t);
        ld ez = l / 2 - l / 2 * cos(2 * M_PI * e / t);
        cout << setprecision(15) << atan2(ez, sqrt(x * x + (y - ey) * (y - ey))) / (2 * M_PI) * 360 << endl;
    }
}