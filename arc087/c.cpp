#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        m[x]++;
    }
    ll result = 0;
    for (const auto [k, v]: m) {
        if (v > k) result += v - k;
        if (v < k) result += v;
    }
    cout << result << endl;
}
