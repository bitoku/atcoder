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
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            b[i] = a[i];
            s[i] = a[i];
        }
        else {
            b[i] = max(a[i], b[i-1]);
            s[i] = a[i] + s[i-1];
        }
    }
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        cout << t + s[i] + b[i]*(i+1) << endl;
        t += s[i];
    }
}