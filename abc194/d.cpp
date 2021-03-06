#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    double result = 0;
    for (int i = n; i >= 2; --i) {
        result += (double)n / (i - 1);
    }
    cout << setprecision(12) << result << endl;
}
