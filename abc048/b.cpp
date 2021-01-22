#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    unsigned long long a, b, x, result;
    cin >> a >> b >> x;
    if (a > 0) {
        result = (b / x) - ((a-1) / x);
    } else {
        result = (b / x) + 1;
    }
    cout << result << endl;
}

