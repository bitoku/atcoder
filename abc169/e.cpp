#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1) {
        int k = n / 2;
        cout << b[k] - a[k] + 1 << endl;
    } else {
        int k = n / 2 - 1;
        cout << (b[k] + b[k + 1]) - (a[k] + a[k+1]) + 1 << endl;
    }
}
