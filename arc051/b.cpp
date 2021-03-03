#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int k;
    cin >> k;
    int a = 2, b = 1;
    for (int i = 1; i < k; ++i) {
        b = a + b;
        swap(a, b);
    }
    cout << a << ' ' << b << endl;
}
