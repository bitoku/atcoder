#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, y;
    cin >> n >> y;
    for (int a = 0; a <= y && a <= n; ++a) {
        for (int b = 0; a * 10000 + b * 5000 <= y && a + b <= n; ++b) {
            int c = (y - (a * 10000 + b * 5000)) / 1000;
            if (a + b + c == n) {
                printf("%d %d %d\n", a, b, c);
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}
