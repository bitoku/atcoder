#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int a[4];
    for (int i = 0; i < 4; ++i) {
        a[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s == "AC") {
            a[0]++;
        } else if (s == "WA") {
            a[1]++;
        } else if (s == "TLE") {
            a[2]++;
        } else if (s == "RE") {
            a[3]++;
        }
    }
    cout << "AC x " << a[0] << endl;
    cout << "WA x " << a[1] << endl;
    cout << "TLE x " << a[2] << endl;
    cout << "RE x " << a[3] << endl;

}
