#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> aa;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        aa[a[i]]++;
    }
    if (aa.size() > 2) {
        cout << "No" << endl;
        return 0;
    }
    if (aa.size() == 2) {
        auto [x1, y1] = *aa.begin();
        auto [x2, y2] = *aa.rbegin();
        if (abs(x1 - x2) > 1) {
            cout << "No" << endl;
            return 0;
        }
        if (x2 - y1 > 0 && (n - y1) / (x2 - y1) > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    if (aa.size() == 1) {
        auto x = aa.begin()->first;
        if (x == n-1 || n / x > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}