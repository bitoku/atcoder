#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<long long, long long> m;
    long long s = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        m[a]++;
        s += a;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        long long b, c;
        cin >> b >> c;
        s -= m[b] * b;
        s += m[b] * c;
        m[c] += m[b];
        m[b] = 0;
        cout << s << endl;
    }
    return 0;
}
