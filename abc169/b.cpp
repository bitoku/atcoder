#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    unsigned long long result = 1;
    bool over = false;
    cin >> n;
    for (int i=0;i<n;i++) {
        unsigned long long a;
        cin >> a;
        if (a == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (1000000000000000000 / a < result) {
            over = true;
            continue;
        }
        result *= a;
    }
    if (over) {
        cout << -1 << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}
