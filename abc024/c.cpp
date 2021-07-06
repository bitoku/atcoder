#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, d, k;
    cin >> n >> d >> k;
    vector<ll> l(d), r(d);
    vector<int> s(k), t(k);
    for (int i = 0; i < d; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> s[i] >> t[i];
    }
    for (int i = 0; i < k; ++i) {
        ll left = s[i], right = s[i];
        for (int j = 0; j < d; ++j) {
            if (right < l[j] || r[j] < left) continue;
            left = min(left, l[j]);
            right = max(right, r[j]);
            if (left <= t[i] && t[i] <= right) {
                cout << j + 1 << endl;
                break;
            }
        }
    }
}