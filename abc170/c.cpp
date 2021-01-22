#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, N;
    cin >> X >> N;
    map<int, int> p;
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        p[k] = 1;
    }
    for (int j = 0; j <= 100; ++j) {
        if (p[X - j] == 0) {
            cout << X - j << endl;
            return 0;
        }
        if (p[X + j] == 0) {
            cout << X + j << endl;
            return 0;
        }
    }
}
