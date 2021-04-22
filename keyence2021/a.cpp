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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) a[i] = max(a[i-1], a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll m = 0;
    for (int i = 0; i < n; ++i) {
        cout << max(m, a[i] * b[i]) << endl;
        m = max(m, a[i] * b[i]);
    }
}
