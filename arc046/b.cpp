#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (a >= n) {
        cout << "Takahashi" << endl;
        return 0;
    }
    if (a > b) {
        cout << "Takahashi" << endl;
        return 0;
    }
    if (b > a) {
        cout << "Aoki" << endl;
        return 0;
    }
    if (n % (a + 1) == 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Takahashi" << endl;
    }
}
