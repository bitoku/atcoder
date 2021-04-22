#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll l = 140, r = 170;
    ll c, d;
    cin >> c >> d;
    ll result = 0;
    while (l < d) {
        result += max(0ll, min(d, r) - max(c, l));
        l <<= 1; r <<= 1;
    }
    cout << result << endl;
}
