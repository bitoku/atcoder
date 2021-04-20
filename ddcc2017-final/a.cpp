#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll k;
    cin >> k;
    ll resulta = 0;
    ll resultb = 0;
    for (ll i = 0; i < 200; i += k) {
        for (ll j = 0; j < 200; j += k) {
            if (
                    (i - 100) * (i - 100) + (j - 100) * (j - 100) <= 100 * 100 &&
                    (i + k - 100) * (i + k - 100) + (j - 100) * (j - 100) <= 100 * 100 &&
                    (i - 100) * (i - 100) + (j + k - 100) * (j + k - 100) <= 100 * 100 &&
                    (i + k - 100) * (i + k - 100) + (j + k - 100) * (j + k - 100) <= 100 * 100
            ) {
                resulta++;
            }
        }
    }
    for (ll i = 0; i < 300; i += k) {
        for (ll j = 0; j < 300; j += k) {
            if (
                    (i - 150) * (i - 150) + (j - 150) * (j - 150) <= 150 * 150 &&
                    (i + k - 150) * (i + k - 150) + (j - 150) * (j - 150) <= 150 * 150 &&
                    (i - 150) * (i - 150) + (j + k - 150) * (j + k - 150) <= 150 * 150 &&
                    (i + k - 150) * (i + k - 150) + (j + k - 150) * (j + k - 150) <= 150 * 150
                    ) {
                resultb++;
            }
        }
    }
    cout << resulta << ' ' << resultb << endl;
}
