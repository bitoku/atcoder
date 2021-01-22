#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int s = 0;
    for (int j = 0; j < K; ++j) {
        s += A[j];
    }
    cout << s << endl;
    return 0;
}
