#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll a, b;
    ll ret = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ret += (a + b) * (b - a + 1) / 2;
    }
    cout << ret << endl;
}
