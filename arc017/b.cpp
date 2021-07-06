#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll result = 0;
    int cnt = 1;
    if (cnt >= k) result++;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i+1]) cnt++;
        else cnt = 1;
        if (cnt >= k) result++;
    }
    cout << result << endl;
}
