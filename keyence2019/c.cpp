#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll result = 0;
    vector<ll> c(n);
    ll diff = 0;
    for (int i = 0; i < n; ++i) {
        c[i] = b[i] - a[i];
        if (c[i] > 0) {
            result++;
            diff += c[i];
        }
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n && c[i] < 0 && diff > 0; ++i) {
        diff += c[i];
        result++;
    }
    if (diff <= 0) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
}