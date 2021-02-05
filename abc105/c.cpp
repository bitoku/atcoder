#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    deque<int> dq;
    if (n == 0) {
        cout << 0 << endl;
    }
    while (n != 0) {
        if (n % 2 != 0) {
            dq.push_front(1);
            n--;
        } else {
            dq.push_front(0);
        }
        n /= -2;
    }
    for (int i : dq) {
        cout << i;
    }
    cout << endl;
}
