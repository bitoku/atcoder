#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> x(n+1);
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        x[a]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (q - x[i] >= k) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
