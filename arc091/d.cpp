#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    ll cnt = 0;
    for (int b = k + 1; b <= n; ++b) {
        for (int m = 0; m * b <= n; ++m) {
            cnt += max(min(n - m * b + 1, b) - k, 0);
            if (m == 0 && k == 0) cnt--;
        }
    }
    cout << cnt << endl;
}

//int main() {
//    int n, k;
//    cin >> n >> k;
//    int cnt = 0;
//    for (int b = k + 1; b <= n; ++b) {
//        int p = n / b;
//        int r = n % b;
//        cnt += p * max(0, b - k) + max(0, r - k + 1);
//        if (k == 0) cnt--;
//    }
//    cout << cnt << endl;
//}
