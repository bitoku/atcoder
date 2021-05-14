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
    ll l = 0;
    ll x = 0;
    ll result = 0;
    for (int r = 0; r < n; ++r) {
        x += a[r];
        while (x > n) {
            x -= a[l];
            l++;
        }
        if (x == n) result++;
    }
    cout << result << endl;
}