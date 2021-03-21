#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int m = 0;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m = max(x, m);
        result += m - x;
    }
    cout << result << endl;
}
