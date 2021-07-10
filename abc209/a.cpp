#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a, b;
    cin >> a >> b;
    cout << max(0ll, b - a + 1) << endl;
}