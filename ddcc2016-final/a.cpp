#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll r, c;
    cin >> r >> c;
    ll result = 0;
    for (ll i = c; i < r; i += c) {
        for (ll j = c; j < r; j += c) {
            if (i * i + j * j <= r * r) result += 4;
        }
    }
    cout << result << endl;
}
