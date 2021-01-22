#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll exp = 0;
    while (x * (a - 1) < b) {
        if (x >= LONG_LONG_MAX / a) {
            break;
        }
        x *= a;
        if (x >= y) {
            cout << exp << endl;
            return 0;
        }
        exp++;
    }
    exp += (y - x - 1) / b;
    cout << exp << endl;
}
