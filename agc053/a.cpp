#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TOOO: solve without editorial

int main() {
    ll n;
    cin >> n;
    ++n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> d(n-1);
    ll k = LONG_LONG_MAX;
    for (int i = 0; i < n - 1; ++i) {
        d[i] = abs(a[i+1] - a[i]);
        k = min(d[i], k);
    }
    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << (a[0] + i) / k;
        for (int j = 1; j < n; ++j) {
            cout << ' ' << (a[j] + i) / k;
        }
        cout << endl;
    }
}
