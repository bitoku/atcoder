#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    ll result = 0;
    ll a = LONG_LONG_MAX;
    result += b[0];
    for (int i = 0; i < n - 2; ++i) {
        result += min(b[i], b[i+1]);
    }
    result += b[n-2];
    cout << result << endl;
}
