#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll result = 0;
    for (ll i = 1000; i <= n; i *= 1000) {
        result += n - (i - 1);
    }
    cout << result << endl;
}
