#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    if (N % 1000 == 0) {
        cout << 0 << endl;
    } else {
        cout << 1000 - N % 1000 << endl;
    }
}
