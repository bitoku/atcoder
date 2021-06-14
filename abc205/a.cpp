#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ld a, b;
    cin >> a >> b;
    ld x = a / 100;
    cout << setprecision(12) << b * x << endl;
}