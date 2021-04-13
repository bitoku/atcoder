#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    // a ^ b = c
    // b ^ c = a
    // c ^ a = b
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    if (m.size() > 3) {
        cout << "No" << endl;
        return 0;
    }
    if (m.size() == 1) {
        auto it = m.begin();
        if ((*it).first == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    if (m.size() == 2) {
        auto it = m.begin();
        if ((*it).first == 0 && (*it).second * 2 == (*(++it)).second) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    if (m.size() == 3) {
        auto it = m.begin();
        auto x = (*it);
        auto y = (*(++it));
        auto z = (*(++it));
        if ((x.first ^ y.first) == z.first && x.second == y.second && y.second == z.second) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
