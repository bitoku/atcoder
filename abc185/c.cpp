#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll memo[200][20];

ll pascal(ll n, ll r) {
    if (memo[n][r]) return memo[n][r];
    if (r == 0 || n == r) return 1;
    memo[n][r] = pascal(n-1, r-1) + pascal(n-1, r);
    return memo[n][r];
}

int main() {
    ll l;
    cin >> l;
    cout << pascal(l - 1, 11) << endl;
}
