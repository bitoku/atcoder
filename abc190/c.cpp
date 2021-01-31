#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i] >> d[i];
    }
    int result = 0;
    for (int i = 0; i < (ll)pow(2, k); ++i) {
        vector<bool> plate(n);
        bitset<16> pattern(i);
        for (int j = 0; j < k; ++j) {
            if (pattern[j]) {
                plate[c[j]] = true;
            } else {
                plate[d[j]] = true;
            }
        }
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (plate[a[j]] && plate[b[j]]) {
                cnt++;
            }
        }
        result = max(result, cnt);
    }
    cout << result << endl;

}
