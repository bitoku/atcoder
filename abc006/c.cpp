#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll b = 0;
    if (m % 2 == 1) b = 1;
    for (; b <= n && b * 3 <= m; b += 2) {
        ll a = (4 * n - b - m) / 2;
        if (a < 0 || a + b > n) continue;
        cout << a << ' ' << b << ' ' << n - a - b << endl;
        return 0;
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}