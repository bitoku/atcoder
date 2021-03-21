#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    ll t = abs(x) / d;
    if (x > 0) {
        x -= min(k, t) * d;
    } else {
        x += min(k, t) * d;
    }
    if (k <= t) {
        cout << abs(x) << endl;
        return 0;
    }
    k -= t;
    if (x > 0) {
        if (k % 2 == 0) {
            cout << x << endl;
        } else {
            cout << abs(x - d) << endl;
        }
    } else {
        if (k % 2 == 0) {
            cout << abs(x) << endl;
        } else {
            cout << abs(x + d) << endl;
        }
    }
}
