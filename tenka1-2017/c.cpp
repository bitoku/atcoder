#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; ++h) {
        for (ll n = 1; n <= 3500; ++n) {
            ll k = 4 * h * n - N * n - N * h;
            if (k <= 0) continue;
            if (N * h * n % k == 0) {
                cout << h << ' ';
                cout << n << ' ';
                cout << N * h * n / k << endl;
                return 0;
            }
        }
    }
}
