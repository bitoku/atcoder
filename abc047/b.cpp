#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    ll xmn = 0, xmx = w, ymn = 0, ymx = h;
    for (int i = 0; i < n; ++i) {
        ll x, y, a;
        cin >> x >> y >> a;
        if (a == 1) xmn = max(xmn, x);
        if (a == 2) xmx = min(xmx, x);
        if (a == 3) ymn = max(ymn, y);
        if (a == 4) ymx = min(ymx, y);
    }
    cout << max(0ll, xmx - xmn) * max(0ll, ymx - ymn) << endl;
}
