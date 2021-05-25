#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll a = 0, b = 0, c = 0;
    ll result = LONG_LONG_MAX;
    while (n > (1ll << b)) {
        a = n / (1ll << b);
        c = n % (1ll << b);
        result = min(result, a+b+c);
        b++;
    }
    if (b == 0) cout << 1 << endl;
    else cout << result << endl;
}