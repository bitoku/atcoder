#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> b(n+1);
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        b[i+1] = b[i] + a;
    }
    ll m = LONG_LONG_MAX;
    for (int i = 1; i < n; ++i) {
        m = min(m, abs(b[i] - (b[n] - b[i])));
    }
    cout << m << endl;
}
