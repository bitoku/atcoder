#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll s = 0;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (t == 1) {
            swap(a[(s + x) % n], a[(s + y) % n]);
        } else if (t == 2) {
            s = (s - 1 + n) % n;
        } else {
            cout << a[(s + x) % n] << endl;
        }
    }
}