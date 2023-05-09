#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    cout << setprecision(15) << fixed;
    cout << (double) 1 / f << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

