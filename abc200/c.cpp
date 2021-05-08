#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> m(200);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i] % 200]++;
    }
    ll result = 0;
    for (int i = 0; i < 200; ++i) {
        result += m[i] * (m[i] - 1) / 2;
    }
    cout << result << endl;
}