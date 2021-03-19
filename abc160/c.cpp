#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    ll maxdiff = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = (a[(i+1) % n] - a[i] + k) % k;
        maxdiff = max(maxdiff, b[i]);
    }
    cout << k - maxdiff << endl;
}
