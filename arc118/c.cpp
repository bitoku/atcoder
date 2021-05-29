#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    a[1] = 6;
    a[2] = 10;
    a[3] = 15;
    set<ll> s;
    for (int i = 2; i * a[1] <= 10000; ++i) {
        if (a[1] * i <= 10000) s.insert(a[1] * i);
        if (a[2] * i <= 10000) s.insert(a[2] * i);
        if (a[3] * i <= 10000) s.insert(a[3] * i);
    }
    for (int i = 4; i <= n; ++i) {
        a[i] = *s.begin();
        s.erase(s.begin());
    }
    cout << a[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}