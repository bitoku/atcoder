#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = -LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll ma = -LONG_LONG_MAX;
        ll mt = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            ll aoki = 0;
            ll takahashi = 0;
            int l = min(i, j);
            int r = max(i, j);
            for (int k = l; k <= r; ++k) {
                if ((k - l) % 2 == 0) takahashi += a[k];
                else aoki += a[k];
            }
            if (aoki > ma) {
                ma = aoki;
                mt = takahashi;
            }
        }
        result = max(result, mt);
    }
    cout << result << endl;
}
