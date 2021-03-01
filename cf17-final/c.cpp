#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n;
    cin >> n;
    int D[13] = {};
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        D[a]++;
    }
    D[0]++;
    for (int i = 0; i <= 12; ++i) {
        if (((i == 0 || i == 12) && D[i] >= 2) || D[i] >= 3) {
            cout << "0" << endl;
            return 0;
        }
    }
    int result = 0;
    for (int i = 0; i <= (1 << 11); ++i) {
        bitset<11> bit(i);
        bool k[24] = {};
        for (int j = 1; j <= 11; ++j) {
            if (D[j] == 1) {
                if (bit[j-1]) k[j] = true;
                else k[24-j] = true;
            } else if (D[j] == 2) {
                k[j] = true;
                k[24-j] = true;
            }
        }
        if (D[0] == 1) {
            k[0] = true;
        }
        if (D[12] == 1) {
            k[12] = true;
        }
        int before = -24;
        int diff = 24;
        for (int j = 0; j < 24; ++j) {
            if (k[j]) {
                diff = min({diff, j - before, 24 - j});
                before = j;
            }
        }
        result = max(result, diff);
    }
    cout << result << endl;
}
