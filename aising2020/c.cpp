#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll result = 0;
        for (int x = 1; x * x < i; ++x) {
            for (int y = 1; x * x + y * y + x * y < i; ++y) {
                for (int z = 1; x * x + y * y + z * z + x * y + y * z + z * x <= i; ++z) {
                    if (x * x + y * y + z * z + x * y + y * z + z * x == i) {
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }
}
