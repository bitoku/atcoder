#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        a[x]++;
        a[y]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}