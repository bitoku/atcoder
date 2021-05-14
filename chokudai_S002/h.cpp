#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] == b[i]) {
            cout << -1 << endl;
        } else {
            cout << abs(b[i] - a[i]) << endl;
        }
    }
}