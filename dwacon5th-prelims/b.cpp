#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> aa(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        aa[i+1] += aa[i] + a[i];
    }
    vector<ll> aaa;
    for (int i = 0; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            aaa.push_back(aa[j]-aa[i]);
        }
    }
    ll x = 0;
    ll i = 1;
    while (i <= aa[n]) i <<= 1;
    while (i > 0) {
        ll cnt = 0;
        ll temp = x + i;
        for (long long y : aaa) {
            if ((temp & y) == temp) cnt++;
        }
        if (cnt >= k) {
            x = temp;
        }
        i >>= 1;
    }
    cout << x << endl;
}
