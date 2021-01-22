#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int s = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        s = (s ^ A[i]);
    }
    for (int i = 0; i < N; ++i) {
        cout << (s ^ A[i]) << endl;
    }
}
