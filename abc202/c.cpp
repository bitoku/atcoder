#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        result += m[b[c[i]-1]];
    }
    cout << result << endl;
}