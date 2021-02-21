#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int k;
    cin >> k;
    ll result = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k && i * j <= k; ++j) {
            result += k / i / j;
        }
    }
    cout << result << endl;
}
