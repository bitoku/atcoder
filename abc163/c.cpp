#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n-1; ++i) {
        int a;
        cin >> a;
        m[--a]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << m[i] << endl;
    }
}
