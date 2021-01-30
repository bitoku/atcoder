#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    bool hate[10] = {0};
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        hate[x] = true;
    }
    for (int i = n; i < 100000; ++i) {
        int pay = i;
        bool payable = true;
        while (pay > 0) {
            if (hate[pay % 10]) {
                payable = false;
                break;
            }
            pay /= 10;
        }
        if (payable) {
            cout << i << endl;
            return 0;
        }
    }
}
