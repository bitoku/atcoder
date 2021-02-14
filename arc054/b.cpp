#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    double p;
    cin >> p;
    double x = 1.5 / log(2) * log(p * log(2) / 1.5);
    if (x < 0) {
        cout << setprecision(12) << p << endl;
        return 0;
    }
    double a = x + 1.5 / log(2);
    cout << setprecision(12) << a << endl;
}
