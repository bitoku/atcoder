#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    ll result = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i+1]) cnt++;
        else cnt = 0;
        if (cnt >= k - 1) result++;
    }
    cout << result << endl;
}
