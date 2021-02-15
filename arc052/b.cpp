#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Corn {
    double x;
    double h;
    double r;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<Corn> corns(n);
    for (int i = 0; i < n; ++i) {
        cin >> corns[i].x >> corns[i].r >> corns[i].h;
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        double result = 0;
        for (auto & corn : corns) {
            double temp = 0;
            if (corn.x + corn.h <= a || b <= corn.x) continue;
            double r = corn.r;
            double h = corn.h;
            if (corn.x < a && a < corn.x + corn.h) {
                r = corn.r / corn.h * (corn.h + corn.x - a);
                h = corn.h + corn.x - a;
            }
            temp += M_PI * r * r * h / 3;

            r = 0, h = 0;
            if (corn.x < b && b < corn.x + corn.h) {
                r = corn.r / corn.h * (corn.h + corn.x - b);
                h = corn.h + corn.x - b;
            }
            temp -= M_PI * r * r * h / 3;
            result += temp;
        }
        cout << setprecision(8) << result << endl;
    }
}
