#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (int i = 0; i < r; i++) {
        int x;
        cin >> x;
        a[x-1]++;
    }
    if (n == r) {
        cout << "*\n";
        return;
    }
    for (int i = 0; i < n; i++) if (!a[i]) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}
