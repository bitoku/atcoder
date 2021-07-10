#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 1) a[i]--;
        sum += a[i];
    }
    if (sum <= x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}