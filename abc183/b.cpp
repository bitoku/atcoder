#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    string s;
    cin >> n >> x;
    cin >> s;
    for (auto c: s) {
        if (c == 'x') {
            x = max(x-1, 0);
        } else if (c == 'o') {
            x++;
        }
    }
    cout << x << endl;
}
