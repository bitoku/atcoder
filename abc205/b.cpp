#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<bool> a(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[x-1] = true;
    }
    if (all_of(a.begin(), a.end(), [](bool x){return x;})) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}