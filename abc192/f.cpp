#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if ((x - sum) % n == 0) {
        cout << (x - sum) / n << endl;
        return 0;
    }
    vector<ll> b(n);
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        b[i] = sum - a[i];
        if ((x - b[i]) % (n-1) == 0) {
            result = min(result, (x - b[i]) / (n - 1));
        }
    }
    cout << result << endl;
}
