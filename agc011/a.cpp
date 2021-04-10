#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    ll last = LONG_LONG_MIN;
    ll cap = 0;
    ll result = 0;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < n; ++i) {
        if (last + k >= t[i] && cap < c) {
            cap++;
        } else {
            result++;
            last = t[i];
            cap = 1;
        }
    }
    cout << result << endl;
}
