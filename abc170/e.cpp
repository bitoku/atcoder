#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<multiset<ll>> vs(200000);
    vector<ll> rate(n);
    vector<int> cls(n);
    for (int i = 0; i < n; ++i) {
        cin >> rate[i] >> cls[i];
        cls[i]--;
        vs[cls[i]].insert(rate[i]);
    }
    multiset<ll> maxrates;
    for (int i = 0; i < 200000; ++i) {
        if (!vs[i].empty()) maxrates.insert(*vs[i].rbegin());
    }
    for (int i = 0; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        auto it1 = maxrates.find(*vs[cls[c]].rbegin());
        maxrates.erase(it1);
        auto it2 = vs[cls[c]].find(rate[c]);
        vs[cls[c]].erase(it2);
        if (!vs[cls[c]].empty()) maxrates.insert(*vs[cls[c]].rbegin());
        cls[c] = d;
        if (!vs[cls[c]].empty()) {
            auto it3 = maxrates.find(*vs[cls[c]].rbegin());
            maxrates.erase(it3);
        }
        vs[cls[c]].insert(rate[c]);
        maxrates.insert(*vs[cls[c]].rbegin());
        cout << *maxrates.begin() << endl;
    }
}