#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> a;
    for (int i = 0; i < n; ++i) {
        auto it = b.rbegin();
        ll idx = n - i;
        bool ok = false;
        while (it != b.rend()) {
            if (*it == idx) {
                a.push_back(*it);
                b.erase(--(it.base()));
                ok = true;
                break;
            }
            it++;
            idx--;
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}