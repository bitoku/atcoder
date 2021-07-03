#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    ld rate = 0;
    for (int i = n - k; i < n; ++i) {
        rate = (rate + r[i]) / 2;
    }
    cout << setprecision(12) << rate << endl;
}