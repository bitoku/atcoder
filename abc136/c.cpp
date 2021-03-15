#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = n-1; i >= 1; --i) {
        if (h[i] < h[i-1]) {
            h[i-1]--;
            if (h[i] < h[i-1]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
