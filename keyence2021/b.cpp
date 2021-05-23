#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        m[a]++;
    }
    ll result = 0;
    ll mx = m.rbegin()->first;
    ll rest = k;
    for (int i = 0; i <= mx; ++i) {
        result += max(0ll, (rest - m[i]) * i);
        rest -= max(0ll, (rest - m[i]));
    }
    result += rest * (mx + 1);
    cout << result << endl;
}