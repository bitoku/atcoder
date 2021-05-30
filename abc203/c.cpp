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
        ll a, b;
        cin >> a >> b;
        m[a] += b;
    }
    ll result = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->first - result > k) {
            result += k;
            k = 0;
            break;
        }
        k -= it->first - result;
        result = it->first;
        k += it->second;
    }
    result += k;
    cout << result << endl;
}