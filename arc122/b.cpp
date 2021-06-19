#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> s(n + 1);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = a[i] + s[i];
    }
    ld result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        result = min(result, s[n] - s[i + 1] - (n - 2 * i - 2) * ((ld)a[i] / 2));
    }
    cout << setprecision(15) << result / n << endl;
}