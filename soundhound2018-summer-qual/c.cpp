#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    if (d != 0) {
        cout << setprecision(12) << (ld)2 * (n - d) * (m - 1) / n / n << endl;
    } else {
        cout << setprecision(12) << (ld)n * (m - 1) / n / n << endl;
    }
}