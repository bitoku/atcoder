#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n+1);
    ll temp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        temp += a[i] * i;
        b[i+1] = a[i] + b[i];
    }
    ll result = temp + (n - 1) * (n - 2) / 2;
    for (ll i = 1; i < n; ++i) {
        temp += b[i] - (b[n] - b[i]);
        if (i % 2 == 0) {
            result = min(result, temp + (i - 1) * i / 2 + (n - 1 - i) * (n - 2 - i) / 2);
        }
    }
    cout << result << endl;
}