#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b + 1) b = a[i];
    }
    if (b == 0) cout << -1 << endl;
    else cout << n - b << endl;
}
