#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    deque<ll> array;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (i % 2 == 0) {
            array.push_back(a);
        } else {
            array.push_front(a);
        }
    }
    if (n % 2 == 1) {
        reverse(array.begin(), array.end());
    }
    cout << array[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << array[i];
    }
    cout << endl;
}
