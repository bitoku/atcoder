#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    ll sum = n * 100 + m * 1800;
    sum <<= m;
    cout << sum << endl;
}
