#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ll t = a[i];
        ll d = 0;
        while (t > 0) {
            t /= 10;
            d++;
        }
        for (int j = 0; j < d; ++j) {
            result = (result * 10) % mod;
        }
        result = (result + a[i]) % mod;
    }
    cout << result << endl;
}
