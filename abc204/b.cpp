#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        result += max(a - 10, 0ll);
    }
    cout << result << endl;
}