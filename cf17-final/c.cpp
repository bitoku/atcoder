#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial 06/26

int main() {
    ll n;
    cin >> n;
    vector<ll> d(13);
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        d[min(a, 24 - a)]++;
    }
    ll result = 0;
    if (d[0] >= 2 || d[12] >= 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int t = 0; t < (1 << 11); ++t) {
        vector<ll> time(24);
        for (int i = 1; i < 12; ++i) {
            if (d[i] == 0) continue;
            if (d[i] == 2) {
                time[i] = 1;
                time[(24 - i) % 24] = 1;
            }
            if (d[i] > 2) {
                cout << 0 << endl;
                return 0;
            }
            if (t & (1 << (i - 1))) {
                time[i] = 1;
            } else {
                time[(24 - i) % 24] = 1;
            }
        }
        if (d[12] == 1) {
            time[12] = 1;
        }
        ll k = 0;
        ll temp = 12;
        for (int i = 1; i < 24; ++i) {
            if (!time[i]) continue;
            temp = min(temp, i - k);
            k = i;
        }
        temp = min(temp, 24 - k);
        result = max(result, temp);
    }
    cout << result << endl;
}