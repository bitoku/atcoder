#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int d1, d2;
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    d1 = c1 - c2;
    d2 = c2 - c3;
    for (int i = 1; i < 3; ++i) {
        cin >> c1 >> c2 >> c3;
        if (c1 - c2 == d1 && c2 - c3 == d2) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
