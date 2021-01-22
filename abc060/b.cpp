#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    int m = a % b;
    do {
        if (m == c) {
            cout << "YES" << endl;
            return 0;
        }
        m = (m + a) % b;
    } while(m != a % b);
    cout << "NO" << endl;
}
