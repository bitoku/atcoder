#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll colorcnt[3] = {0};
    ll result = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int cnt = 0;
        bool added = false;
        for (long long & color : colorcnt) {
            if (color == a[i]) {
                cnt++;
                if (!added) {
                    color++;
                    added = true;
                }
            }
        }
        result = (result * cnt) % mod;
    }
    cout << result << endl;
}
