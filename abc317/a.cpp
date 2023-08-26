#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int h, x;
    cin >> h >> x;
    int diff = x - h;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if (p >= diff) {
            cout << i+1 << endl;
            return 0;
        }
    }
}