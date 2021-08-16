#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<int> l(n), r(n);
    ld result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; ++j) {
            ld temp = 0;
            for (int k = 0; k < i; ++k) {
                temp += (ld)max(0, r[k] - max(j, l[k] - 1)) / (r[k] - l[k] + 1) / (r[i] - l[i] + 1);
            }
            result += temp;
        }
    }
    cout << setprecision(12) << result << endl;
}