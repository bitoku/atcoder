#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            result += i * 100 + j;
        }
    }
    cout << result << endl;
}