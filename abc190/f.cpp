#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

class Bit {
public:
int size;
vector<int> tree;
explicit Bit(int n) {
    size = n;
    tree.resize(n + 1);
}

ll sum(int i) const {
    ll s = 0;
    while (i > 0) {
        s += tree[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= size) {
        tree[i] += x;
        i += i & -i;
    }
}

void sub(int i, int x) {
    while (i <= size) {
        tree[i] -= x;
        i += i & -i;
    }
}
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    Bit b(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]++;
        b.add(a[i], 1);
        result += i + 1 - b.sum(a[i]);
    }
    cout << result << endl;
    for (int i = 0; i < n - 1; ++i) {
        result += (n - a[i] - (a[i] - 1));
        cout << result << endl;
    }
}
