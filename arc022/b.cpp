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
    int r = 0;
    int result = 0;
    bool taste[100010] = {};
    for (int l = 0; l < n; ++l) {
        while (r < n && !taste[a[r]]) {
            taste[a[r]] = true;
            result = max(result, r - l + 1);
            r++;
        }
        if (r >= n) break;
        while (l < n && a[l] != a[r]) {
            taste[a[l]] = false;
            l++;
        }
        r++;
    }
    cout << result << endl;
}
