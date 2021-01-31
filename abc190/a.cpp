#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0) {
        if (a <= b) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
    } else {
        if (b <= a) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
    }
}
