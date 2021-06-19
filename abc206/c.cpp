#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    map<ll, ll> m;
    ll n;
    cin >> n;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        result += i - m[a];
        m[a]++;
    }
    cout << result << endl;
}