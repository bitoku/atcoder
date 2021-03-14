#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int a, b, w;
    cin >> a >> b >> w;
    int ma = INT_MAX, mb = 0;
    for (int i = 0; i * a <= w * 1000; ++i) {
        if (a * i <= w * 1000 && w * 1000 <= b * i) {
            mb = max(mb, i);
            ma = min(ma, i);
        }
    }
    if (ma == INT_MAX) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    cout << ma << ' ' << mb << endl;
}
