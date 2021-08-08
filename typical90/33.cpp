#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << max(H, W) << endl;
    } else {
        cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
    }
}