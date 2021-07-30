#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 07/30

int main() {
    ll d, g;
    cin >> d >> g;
    vector<ll> p(d), c(d);
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }
    ll lim = 1 << d;
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < lim; ++i) {
        ll temp = 0;
        int m = 0;
        ll cnt = 0;
        for (int j = 0; j < d; ++j) {
            if (i & (1 << j)) {
                temp += (j + 1) * 100 * p[j] + c[j];
                cnt += p[j];
            }
            else m = j;
        }
        if (temp >= g) result = min(result, cnt);
        else {
            ll k = (g - temp + (m + 1) * 100 - 1) / ((m + 1) * 100);
            if (k >= p[m]) continue;
            result = min(result, cnt + k);
        }
    }
    cout << result << endl;
}