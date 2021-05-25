#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t, N;
    cin >> t >> N;
    ll k = t;
    vector<ll> v(100, -1);
    ll skip = 0;
    ll cnt = 0;
    while (v[k] == -1) {
        v[k] = (k + t) % 100;
        if (v[k] < k) {
            skip++;
        }
        cnt++;
        k = v[k];
    }
    ll x = (N - 1) / skip * (cnt + skip);
    k = t;
    ll result = 0;
    ll p = N - (N - 1) / skip * skip;
    while (p > 0) {
        x++;
        if (v[k] < k) {
            result = ++x;
            p--;
        }
        k = v[k];
    }
    cout << result << endl;
}