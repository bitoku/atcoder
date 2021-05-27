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
    ll result = a[0] + 1;
    for (int i = 1; i < n; ++i) {
        result *= a[i] - a[i-1] + 1;
        result %= mod;
    }
    cout << result << endl;
}