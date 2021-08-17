#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum / 10 * 10 != sum) {
        cout << "No" << endl;
        return 0;
    }
    int l = 0;
    ll s = 0;
    for (int r = 0; r < 2 * n; ++r) {
        s += a[r % n];
        while (s > sum / 10) {
            s -= a[l % n];
            l++;
        }
        if (s == sum / 10) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}