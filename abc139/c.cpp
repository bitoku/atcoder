#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    cin >> h[0];
    ll cnt = 0;
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        cin >> h[i];
        if (h[i-1] >= h[i]) cnt++;
        else {
            result = max(result, cnt);
            cnt = 0;
        }
    }
    result = max(result, cnt);
    cout << result << endl;
}
