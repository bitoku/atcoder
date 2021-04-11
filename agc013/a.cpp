#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        int up = n, down = n;
        for (int j = i; j < n; ++j) {
            if (a[j] > a[j+1]) {
                up = j;
                break;
            }
        }
        for (int j = i; j < n; ++j) {
            if (a[j] < a[j+1]) {
                down = j;
                break;
            }
        }
        i = max(up, down);
        cnt++;
    }
    cout << cnt << endl;
}
