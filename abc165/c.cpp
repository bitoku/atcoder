#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(const vector<int>& A, const vector<tuple<int, int, int, int>>& q) {
    ll ans = 0;
    for (const auto& t : q) {
        int a = get<0>(t);
        int b = get<1>(t);
        int c = get<2>(t);
        int d = get<3>(t);
        if (A[b] - A[a] == c) ans += d;
    }
    return ans;
}

bool next(vector<int>& A, int m) {
    int end = A.size() - 1;
    while (A[end] == m) end--;
    if (end == -1) return false;
    A[end]++;
    for (end++; end < A.size(); end++) {
        A[end] = A[end-1];
    }
    return true;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(N);
    vector<tuple<int, int, int, int>> q(Q);
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        q[i] = make_tuple(a, b, c, d);
    }
    ll m = 0;
    for (int i = 0; i < N; ++i) {
        A[i] = 1;
    }
    m = check(A, q);
    while (next(A, M)) {
        m = max(m, check(A, q));
    }
    cout << m << endl;
}
