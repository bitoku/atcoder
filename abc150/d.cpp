#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll solve(ll n, ll m, vector<ll>& a) {
    a[0] /= 2;
    ll k = a[0];
    ll bin = 0;
    while (k > 0 && k % 2 == 0) {
        k /= 2;
        bin++;
    }
    for (int i = 1; i < n; ++i) {
        a[i] /= 2;
        k = a[i];
        ll temp_bin = 0;
        while (k > 0 && k % 2 == 0) {
            k /= 2;
            temp_bin++;
        }
        if (bin != temp_bin) {
            return 0;
        }
    }
    ll l = a[0];
    for (int i = 1; i < n; ++i) {
        a[i];
        ll g = gcd(l, a[i]);
        l = l * a[i] / g;
        if (l > 2000000000) {
            return 0;
        }
    }
    if (m < l) {
        return 0;
    }
    m -= l;
    return 1 + m / (2 * l);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(n, m, a) << endl;
}
