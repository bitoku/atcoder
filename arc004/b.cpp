#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        mx += d[i];
    }
    sort(d.begin(), d.end());
    cout << mx << endl;
    if (n == 1) {
        cout << mx << endl;
    } else {
        cout << max(2 * d.back() - mx, 0ll) << endl;
    }
}