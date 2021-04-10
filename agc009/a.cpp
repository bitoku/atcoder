#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    ll result = 0;
    for (int i = n-1; i >= 0; --i) {
        if ((result + a[i]) % b[i]) result += b[i] - (result + a[i]) % b[i];
    }
    cout << result << endl;
}
