#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);
    if ((a - b) % 2 == 0 && (a - c) % 2 == 0) {
        cout << (a - b) / 2 + (a - c) / 2 << endl;
    } else if ((a - b) % 2 == 1 && (a - c) % 2 == 1) {
        cout << (a - b) / 2 + (a - c) / 2 + 1 << endl;
    } else {
        cout << (a - b) / 2 + (a - c) / 2 + 2 << endl;
    }
}
