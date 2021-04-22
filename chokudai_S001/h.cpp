#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b;
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) b.push_back(a[i]);
        else *it = a[i];
    }
    cout << b.size() << endl;
}
