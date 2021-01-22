#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    int x[100005] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        x[a]++;
        x[a+1]++;
        x[a+2]++;
    }
    int m = 0;
    for (int & i : x) {
        m = max(m, i);
    }
    cout << m << endl;
}
