#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    set<tuple<ll, ll, ll>> s;
    ll cnt = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && s.find(make_tuple(a, b, c)) == s.end()) {
        s.insert(make_tuple(a, b, c));
        ll na, nb, nc;
        na = b / 2 + c / 2;
        nb = a / 2 + c / 2;
        nc = a / 2 + b / 2;
        a = na;
        b = nb;
        c = nc;
        cnt++;
    }
    if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}
