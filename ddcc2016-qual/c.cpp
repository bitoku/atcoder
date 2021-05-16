#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> m;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ll g = gcd(a[i], k);
        m[g]++;
    }
    for (auto [d1, v1]: m) {
        for (auto [d2, v2]: m) {
            if (d2 > d1) continue;
            if (d1 * d2 % k == 0) {
                if (d1 == d2) {
                    result += v1 * (v1 - 1) / 2;
                } else {
                    result += v1 * v2;
                }
            }
        }
    }
    cout << result << endl;
}