#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    ld result = (ld)(3 * (n - 1) + (k - 1) * (n - k) * 6 + 1) / (n * n * n);
    cout << setprecision(12) << result << endl;
}