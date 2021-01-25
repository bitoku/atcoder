#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int l = 0; l < n; ++l) {
        ll minn = a[l];
        for (int r = l; r < n; ++r) {
            minn = min(minn, a[r]);
            result = max(result, minn * (r - l + 1));
        }
    }
    cout << result << endl;
}
