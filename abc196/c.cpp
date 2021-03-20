#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll cnt = 0;
    for (ll i = 1; i <= 1000000; ++i) {
        ll t = i;
        ll digit = 1;
        while (t > 0) {
            t /= 10;
            digit *= 10;
        }
        if (i * digit + i > n) break;
        cnt++;
    }
    cout << cnt << endl;
}
