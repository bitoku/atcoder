#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    ll result = 1;
    for (int i = 0; i < n; ++i) {
        result *= c[i] - i;
        result %= mod;
    }
    cout << result << endl;
}