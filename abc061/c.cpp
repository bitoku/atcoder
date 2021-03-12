#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        m[a] += b;
    }
    for (const auto& [a, b]: m) {
        k -= b;
        if (k <= 0) {
            cout << a << endl;
            return 0;
        }
    }
}
