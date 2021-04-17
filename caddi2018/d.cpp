#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    bool odd = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 1) odd = true;
    }
    if (odd) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
}
