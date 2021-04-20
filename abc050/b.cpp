#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> t(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
    }
    ll m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll p, x;
        cin >> p >> x;
        cout << sum - t[--p] + x << endl;
    }
}
