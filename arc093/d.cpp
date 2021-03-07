#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int a, b;
    cin >> a >> b;
    vector<string> grid(100);
    for (int i = 0; i < 50; ++i) {
        grid[i] = string(100, '#');
    }
    for (int i = 50; i < 100; ++i) {
        grid[i] = string(100, '.');
    }
    for (int i = 0; i < a - 1; ++i) {
        grid[(2 * i / 100) * 2][2 * i % 100] = '.';
    }
    for (int i = 0; i < b - 1; ++i) {
        grid[(2 * i / 100) * 2 + 51][2 * i % 100] = '#';
    }
    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
