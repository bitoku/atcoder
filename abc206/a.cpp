#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    if (n * 108 / 100 < 206) {
        cout << "Yay!" << endl;
    } else if (n * 108 / 100 == 206) {
        cout << "so-so" << endl;
    } else {
        cout << ":(" << endl;
    }
}