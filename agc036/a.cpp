#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll s;
    cin >> s;
    if (s == 1000000000000000000LL) {
        cout << 0 << ' ';
        cout << 0 << ' ';
        cout << 1000000000 << ' ';
        cout << 1 << ' ';
        cout << 0 << ' ';
        cout << 1000000000 << endl;
        return 0;
    }
    ll k = s / 1000000000;
    ll y2 = k + 1;
    ll x2 = 1000000000 - s % 1000000000;
    cout << 0 << ' ';
    cout << 0 << ' ';
    cout << 1000000000 << ' ';
    cout << 1 << ' ';
    cout << x2 << ' ';
    cout << y2 << endl;
}
