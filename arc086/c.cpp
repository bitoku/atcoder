#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[x]++;
    }
    sort(a.begin(), a.end(), greater<>());
    ll cnt = 0;
    for (int i = 0; i < k; ++i) {
        cnt += a[i];
    }
    cout << n - cnt << endl;

}
