#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<ll> c(n);
    cin >> a[0] >> b[0];
    ll aa = a[0], bb = b[0];
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        cin >> a[i] >> b[i];
        if ((aa + b[i] - 1) / b[i] < (a[i] + bb - 1) / bb) {
            aa = a[i];
            bb = b[i];
            idx = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == idx) continue;
        if ((aa + b[i] - 1) / b[i] <= (a[i] + bb - 1) / bb) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << idx + 1 << endl;
}