#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 07/11

int main() {
    ll n;
    cin >> n;
    if (n == 3) {
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        return 0;
    }
    if (n == 4) {
        cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
        return 0;
    }
    ll two = n / 4;
    ll three = min(2500ll, n / 4);
    if (n >= 15000) {
        two = 5000;
        three = 2500;
    }
    ll six = n - 2 * two - 2 * three;
    ll a = 2;
    vector<ll> v;
    for (int i = 0; i < two; ++i) {
        v.push_back(a);
        v.push_back(a + 2);
        a += 6;
    }
    ll b = 3;
    for (int i = 0; i < three; ++i) {
        v.push_back(b);
        v.push_back(b + 6);
        b += 12;
    }
    for (int i = 0; i < six; ++i) {
        v.push_back(6 * (1 + i));
    }
    cout << v[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << v[i];
    }
    cout << endl;
}