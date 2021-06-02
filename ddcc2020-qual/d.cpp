#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll m;
    cin >> m;
    ll x = 0;
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        ll d, c;
        cin >> d >> c;
        sum += d * c;
        x += c;
    }
    cout << (sum + 8) / 9 - 1 + x - 1 << endl;
}