#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }
    vector<ll> plus(n);
    vector<ll> pluss(n+1);
    for (int i = 0; i < n; ++i) {
        plus[i] = max(0ll, a[i]);
        pluss[i+1] = pluss[i] + plus[i];
    }
    ll result = 0;
    for (int i = 0; i <= n - k; ++i) {
        result = max(result, pluss[i] + s[k+i] - s[i] + pluss[n] - pluss[k+i]);
        result = max(result, pluss[i] + pluss[n] - pluss[k+i]);
    }
    cout << result << endl;
}