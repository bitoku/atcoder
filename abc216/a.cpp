#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int x, y;
    scanf("%d.%d", &x, &y);
    if (0 <= y && y <= 2) cout << x << '-' << endl;
    if (3 <= y && y <= 6) cout << x << endl;
    if (7 <= y && y <= 9) cout << x << '+' << endl;
}