#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = 0;
    ll tmp = 0;
    for (int i = n-1; i >= 0; --i) {
        if (tmp > 0) tmp--;
        if (a[i] == tmp) {
            continue;
        }
        if (a[i] > tmp) {
            result += a[i];
            tmp = a[i];
        }
        if (a[i] < tmp) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (tmp > 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << result << endl;
}
