#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ld oa, ab, bc;
    cin >> oa >> ab >> bc;
    ld r1 = abs(ab - bc);
    ld R1 = ab + bc;
    ld r2 = max({r1 - oa, oa - R1, 0.0l});
    ld R2 = oa + ab + bc;
    cout << setprecision(12) << (R2 * R2 - r2 * r2) * M_PI << endl;
}