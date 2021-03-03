#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

double a, b, c;

double f(double t) {
    return a * t + b * sin(c * t * M_PI) - 100;
}

double df(double t) {
    return a + b * c * M_PI * cos(c * t * M_PI);
}

int main() {
    cin >> a >> b >> c;
    double x = 100 / a;
    double eps = 0.0000001;
    while (abs(f(x)) > eps) {
        x = x - f(x) / df(x);
    }
    cout << setprecision(12) <<  x << endl;
}
