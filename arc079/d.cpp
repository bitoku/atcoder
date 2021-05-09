#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll k;
    cin >> k;
    ll n = 50;
    ll a = (k + n - 1) / n + 1;
    ll x = (a - 1) * n - k;
    vector<ll> aa(n);
    for (int i = 0; i < x; ++i) {
        aa[i] = a + x - 3;
    }
    for (int i = x; i < n; ++i) {
        aa[i] = n + a - 2 + x;
    }

    cout << n << endl;
    cout << aa[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << aa[i];
    }
    cout << endl;
}