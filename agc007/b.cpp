#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    // a_i = X * i;
    // b_i = X * (n - i) + r_i;
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> r(n);
    for (int i = 0; i < n; ++i) {
        r[p[i]] = i + 1;
    }
    cout << 30000;
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << 30000 * i;
    }
    cout << endl;
    cout << 30000 * (n - 1) + r[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << 30000 * (n - i - 1) + r[i];
    }
    cout << endl;
}
