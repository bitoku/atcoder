#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll mxa = 0;
    ll mnb = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mxa = max(mxa, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        mnb = min(mnb, b[i]);
    }
    cout << max(0ll, mnb - mxa + 1) << endl;
}