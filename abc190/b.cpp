#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, s, d;
    cin >> n >> s >> d;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x >= s || y <= d) {
            continue;
        } else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
