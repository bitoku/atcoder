#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll odd = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 1) odd++;
    }
    if (odd % 2 == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}
