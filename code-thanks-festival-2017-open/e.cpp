#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+10);
    for (int i = 0; i < n; i += 5) {
        cout << '?';
        for (ll j = 0; j < n; ++j) {
            if (i <= j && j < i + 5) {
                cout << ' ' << mod_pow(7ll, j - i, LONG_LONG_MAX);
            } else {
                cout << ' ' << 0;
            }
        }
        cout << endl;
        ll b;
        cin >> b;
        a[i] = b % 7 + 7;
        b = (b - a[i]) / 7;
        a[i+1] = b % 7 + 7;
        b = (b - a[i + 1]) / 7;
        a[i+2] = b % 7 + 7;
        b = (b - a[i + 2]) / 7;
        a[i+3] = b % 7 + 7;
        b = (b - a[i + 3]) / 7;
        a[i+4] = b % 7 + 7;
    }
    cout << '!';
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) cout << ' ' << 1;
        else cout << ' ' << 0;
    }
    cout << endl;
}