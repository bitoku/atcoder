#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += abs(a[i] - b[i]);
    }
    if (cnt <= k && (k - cnt) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}