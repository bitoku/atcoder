#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        ll temp = a[0];
        ll temp_result = 0;
        for (int j = 1; j < n; ++j) {
            if (i & (1 << (j - 1))) temp |= a[j];
            else {
                temp_result ^= temp;
                temp = a[j];
            }
        }
        temp_result ^= temp;
        result = min(result, temp_result);
    }
    cout << result << endl;
}