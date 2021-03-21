#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll solve(ll n) {
    ll result = 0;
    for (int i = 1; i <= n - 1; ++i) {
        result += (n-1) / i;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
