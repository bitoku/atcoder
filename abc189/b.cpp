#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    x *= 100;
    int finish = -1;
    for (int i = 0; i < n; ++i) {
        int v, p;
        cin >> v >> p;
        x -= v * p;
        if (x < 0) {
            finish = i + 1;
            break;
        }
    }
    cout << finish << endl;
}
