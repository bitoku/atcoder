#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    mp[0] = 0;
    ll result = 0;
    while (k > 0) {
        auto it = mp.rbegin();
        auto [x, c] = *it;
        if (x == 0) break;
        auto [tx, tc] = *(++it);
        if (k >= (x - tx) * c) {
            result += (x + tx + 1) * (x - tx) * c / 2;
            k -= (x - tx) * c;
        } else {
            ll t = k / c;
            result += (x + (x - t + 1)) * t * c / 2;
            result += (x - t) * (k % c);
            k = 0;
        }
        auto itt = mp.end();
        mp.erase(--itt);
        it->second += c;
    }
    cout << result << endl;
}