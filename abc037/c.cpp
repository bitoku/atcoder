#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = 0;
    for (int i = 0; i < min(k, n - k); ++i) {
        result += a[i] * (i + 1);
    }
    for (int i = min(k, n - k); i < n - min(k, n - k); ++i) {
        result += a[i] * min(k, n - k + 1);
    }
    for (int i = n - min(k, n - k); i < n; ++i) {
        result += a[i] * (n - i);
    }
    cout << result << endl;
}