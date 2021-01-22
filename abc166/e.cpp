#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> reach(n, 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0) {
            ans += reach[i - a[i]];
        }
        if (i + a[i] < n) reach[i + a[i]] += 1;

    }
    cout << ans << endl;
}
