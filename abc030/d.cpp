#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template< typename T >
T mod_pow(T x, T n, const T &p) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n, a;
    cin >> n >> a;
    a--;
    string k;
    cin >> k;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i]--;
    }
    if (k.size() <= 5) {
        for (int i = 0; i < stoll(k); ++i) {
            a = b[a];
        }
        cout << a+1 << endl;
        return 0;
    }
    set<ll> s;
    vector<ll> route, seen(n, -1);
    ll cnt = 0;
    while (seen[a] < 0) {
        seen[a] = cnt++;
        route.push_back(a);
        a = b[a];
    }
    ll length = cnt - seen[a];
    ll mm = 0;
    for (auto x: k) {
        mm = (mm * 10 + (x - '0')) % length;
    }
    mm = ((mm - seen[a]) % length + length) % length;
    cout << route[mm + seen[a]] + 1 << endl;
}