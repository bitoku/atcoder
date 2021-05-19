#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll mx = LONG_LONG_MIN;
    int mxi = 0;
    ll mn = LONG_LONG_MAX;
    int mni = 0;
    for (int i = 0; i < n; ++i) {
        if (mx < a[i]) {
            mx = a[i];
            mxi = i;
        }
        if (mn > a[i]) {
            mn = a[i];
            mni = i;
        }
    }
    if (abs(mx) >= abs(mn) || mn >= 0) {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n; ++i) {
            cout << mxi+1 << ' ' << i+1 << endl;
        }
        for (int i = 0; i < n-1; ++i) {
            cout << i+1 << ' ' << i+2 << endl;
        }
    } else {
        cout << 2 * n - 1 << endl;
        for (int i = 0; i < n; ++i) {
            cout << mni+1 << ' ' << i+1 << endl;
        }
        for (int i = n; i >= 2; --i) {
            cout << i << ' ' << i-1 << endl;
        }
    }
}