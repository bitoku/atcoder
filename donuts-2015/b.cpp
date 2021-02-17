#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<bitset<16>, ll>> bonus(m);
    for (int i = 0; i < m; ++i) {
        ll b, c;
        cin >> b >> c;
        bitset<16> member(0);
        for (int j = 0; j < c; ++j) {
            int k;
            cin >> k;
            member.set(k-1, true);
        }
        bonus[i] = make_pair(member, b);
    }
    ll result = 0;
    for (ll i = 0; i < (1 << n); ++i) {
        bitset<16> bit(i);
        if (bit.count() != 9) continue;
        ll temp = 0;
        for (int j = 0; j < 16; ++j) {
            if (bit[j]) temp += a[j];
        }
        for (int j = 0; j < m; ++j) {
            if ((bit & bonus[j].first).count() >= 3) {
                temp += bonus[j].second;
            }
        }
        result = max(result, temp);
    }
    cout << result << endl;
}
