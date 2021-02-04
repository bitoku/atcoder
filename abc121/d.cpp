#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll a, b;
    cin >> a >> b;
    ll result = 0;
    if (a % 2 == 1) {
        result = a;
        a++;
    }
    if (((b - a + 1) / 2) % 2 == 0) {
        result ^= 0;
    } else {
        result ^= 1;
    }
    if (b % 2 == 0) {
        result ^= b;
    }
    cout << result << endl;
}
