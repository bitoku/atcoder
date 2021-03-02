#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int k;
    cin >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    if (a[k-1] != 2) {
        cout << -1 << endl;
        return 0;
    }
    ll l = 2, r = 3;
    for (int i = k - 2; i >= 0; --i) {
        l = (l + a[i] - 1) / a[i] * a[i];
        r = r / a[i] * a[i] + a[i] - 1;
        if (l > r) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l << ' ' << r << endl;
}
