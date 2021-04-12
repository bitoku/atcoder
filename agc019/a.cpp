#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll q, h, s, d;
    ll n;
    cin >> q >> h >> s >> d;
    cin >> n;
    if (q * 8 <= min({h * 4, s * 2, d})) {
        cout << n * 4 * q << endl;
    } else if (h * 4 <= min({q * 8, s * 2, d})) {
        cout << n * 2 * h << endl;
    } else if (s * 2 <= min({q * 8, h * 4, d})) {
        cout << n * s << endl;
    } else {
        if (n % 2 == 0) {
            cout << n / 2 * d << endl;
        } else {
            if (q * 8 <= min(h * 4, s * 2)) {
                cout << n / 2 * d + 4 * q << endl;
            } else if (h * 4 <= min(q * 8, s * 2)) {
                cout << n / 2 * d + 2 * h << endl;
            } else if (s * 2 <= min(q * 8, h * 4)) {
                cout << n / 2 * d + s << endl;
            }
        }
    }
}
