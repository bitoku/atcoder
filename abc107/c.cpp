#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    vector<ll> rng(n - k + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (i < n - k + 1) {
            rng[i] = x[i];
        }
        if (i - k + 1 >= 0) {
            rng[i - k + 1] = x[i] - rng[i - k + 1];
        }
    }
    ll m = LONG_LONG_MAX;
    for (int i = 0; i < n - k + 1; ++i) {
        rng[i] += min(abs(x[i]), abs(x[i + k - 1]));
        m = min(m, rng[i]);
    }
    cout << m << endl;
}
