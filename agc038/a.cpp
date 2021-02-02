#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i < b) {
                if (j < a) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                if (j < a) {
                    cout << 0;
                } else {
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}
