#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

ll n, z, w;

int main() {
    cin >> n >> z >> w;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) cout << abs(a.back() - w) << endl;
    else cout << max(abs(a.back() - w), abs(a[n-2] - a.back())) << endl;
}