#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < 10000 && a * i <= n; ++i) {
        for (int j = 0; i + j < 10000 && a * i + b * j <= n; ++j) {
            if ((n - (a * i) - (b * j)) % c == 0) {
                result = min(result, i + j + (n - (a * i) - (b * j)) / c);
            }
        }
    }
    cout << result << endl;
}