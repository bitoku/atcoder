#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ld x0, y0, xn2, yn2;
    cin >> x0 >> y0 >> xn2 >> yn2;
    ld mx = (x0 + xn2) / 2;
    ld my = (y0 + yn2) / 2;
    x0 -= mx;
    y0 -= my;
    ld x1 = x0 * cos(2 * M_PI / n) - y0 * sin(2 * M_PI / n) + mx;
    ld y1 = x0 * sin(2 * M_PI / n) + y0 * cos(2 * M_PI / n) + my;
    cout << setprecision(12) << x1 << ' ' << y1 << endl;
}