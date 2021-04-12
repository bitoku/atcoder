#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    int d = 0;
    int cnt = 0;
    int x = 0;
    while (n > 0) {
        d = n % 10;
        x += d;
        n /= 10;
        cnt++;
    }
    cout << max(x, d - 1 + (cnt-1) * 9) << endl;
}
