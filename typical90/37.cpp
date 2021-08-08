#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll w, n;
    cin >> w >> n;
    vector<ll> spice(w + 1, -1);
    spice[0] = 0;
    for (int i = 0; i < n; ++i) {
        ll l, r, v;
        cin >> l >> r >> v;
        multiset<ll> ms;
        ll left = w - r, right = w - l;
        for (ll j = left+1; j <= right; ++j) {
            ms.insert(spice[j]);
        }
        for (ll j = w; j >= 0 && right >= 0; --j) {
            if (left >= 0) ms.insert(spice[left]);
            if (*ms.rbegin() != -1) {
                spice[j] = max(spice[j], *ms.rbegin() + v);
            }
            auto it = ms.find(spice[right]);
            ms.erase(it);
            right--; left--;
        }
    }
    cout << spice[w] << endl;
}