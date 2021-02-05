#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll result = 0;
    int before = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            before = 0;
            continue;
        }
        result += (a[i] + before) / 2;
        before = (a[i] + before) % 2;
    }
    cout << result << endl;
}
