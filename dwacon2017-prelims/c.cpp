#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    deque<ll> a(n);
    ll x[4] = {};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) x[0]++;
        if (a[i] == 2) x[1]++;
        if (a[i] == 3) x[2]++;
        if (a[i] == 4) x[3]++;
    }
    ll result = x[3];
    ll t = min(x[0], x[2]);
    result += t;
    x[0] -= t;
    x[2] -= t;
    t = x[1] / 2;
    result += t;
    x[1] -= t*2;
    t = min(x[0] / 2, x[1]);
    result += t;
    x[0] -= t * 2;
    x[1] -= t;
    t = min(x[0], x[1]);
    result += t;
    x[0] -= t;
    x[1] -= t;
    t = x[0] / 4;
    result += t;
    x[0] -= t*4;
    t = x[0] / 3;
    result += t;
    x[0] -= t*3;
    t = x[0] / 2;
    result += t;
    x[0] -= t*2;
    result += x[0] + x[1] + x[2];
    cout << result << endl;
}