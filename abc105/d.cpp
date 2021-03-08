#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        b[i+1] = (b[i] + a[i]) % m;
    }
    map<ll, ll> r;
    for (int i = 0; i <= n; ++i) {
        r[b[i]]++;
    }
    ll result = 0;
    for (int i = 0; i <= n; ++i) {
        result += r[b[i]] - 1;
    }
    cout << result / 2 << endl;
}
