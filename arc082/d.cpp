#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == i+1) {
            swap(a[i], a[i+1]);
            result++;
        }
    }
    if (a[n-1] == n) {
        swap(a[n-2], a[n-1]);
        result++;
    }
    cout << result << endl;
}
