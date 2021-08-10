#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> a, b, c;
    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[x % 46]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        b[x % 46]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        c[x % 46]++;
    }
    ll result = 0;
    for (auto [x, i]: a) {
        for (auto [y, j]: b) {
            result += i * j * c[(92 - x - y) % 46];
        }
    }
    cout << result << endl;
}