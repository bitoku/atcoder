#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1,  2);
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            if (a[j] == a[i]) a[j]++;
        }
    }
    cout << a[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}