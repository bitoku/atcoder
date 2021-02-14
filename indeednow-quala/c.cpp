#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> invs(1000001);
    vector<int> sums(1000001);

    int smax = 0;
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        smax = max(smax, s[i]);
        if (s[i] == 0) {
            zero++;
            continue;
        }
        invs[s[i]]++;
    }
    sums[0] = n - zero;
    for (int i = 1; i <= smax; ++i) {
        sums[i] = sums[i-1] - invs[i - 1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        auto it = upper_bound(sums.rbegin(), sums.rend(), k);
        auto score = distance(sums.begin(), it.base());
        cout << score << endl;
    }
}
