#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    long double prob = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= k) {
            prob += 1;
            continue;
        }
        int j = 0;
        while ((i << j) < k) ++j;
        long double temp = 1;
        for (int l = 0; l < j; ++l) {
            temp /= 2;
        }
        prob += temp;
    }
    cout << setprecision(15) << prob / n << endl;
}
