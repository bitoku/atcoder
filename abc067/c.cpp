#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum[i+1] = a[i] + sum[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = 1; i < n; ++i) {
        result = min(result, abs(sum[n] - sum[i] - sum[i]));
    }
    cout << result << endl;
}