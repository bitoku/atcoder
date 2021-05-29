#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (ll i = 0; i <= n - 1; ++i) {
        ll j = n - 1 - i;
        if (a + i * c - j * d <= b && b <= a + i * d - j * c) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}