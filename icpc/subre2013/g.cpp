#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;
int a[maxn][maxn];
typedef pair<int,int> ii;

void solve() {
    int l, c;
    cin >> l >> c;
    int ans = 0;
    bool ok = true;
    for (int i = 0; i < l; i++) {
        int mx = 0, mn = 1e9;
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
        if (mx - mn + 1 != c) ok = false;
    }
    if (!ok) {
        cout << "*\n";
        return;
    }
    vector<ii> op;
    for (int i = 0; i < l; i++) {
        int mn = 1e9;
        for (int j = 0; j < c; j++) {
            mn = min(mn, a[i][j]);
        }
        if (i > 0) {
            for (auto [x, y] : op) {
                swap(a[i][x], a[i][y]);
            }
        }
        else {
            for (int j = 0; j < c; j++) {
                if (a[i][j] != mn + j) {
                    if (a[i][j] - mn < 0) {
                        cout << "*\n";
                        return;
                    }
                    op.emplace_back(j, a[i][j] - mn);
                    swap(a[i][j], a[i][a[i][j] - mn]);
                    j = -1;
                    ans++;
                }
            }
        }
    }
    map<int,int> cc, back;
    for (int i = 0; i < l; i++) cc[a[i][0]];
    int y = 0;
    for (auto &u : cc) {
        u.second = y++;
    }
    for (int i = 0; i < l; i++) {
        a[i][0] = cc[a[i][0]];
    }

    for (int i = 0; i < l; i++) {
        if (a[i][0] != i) {
            swap(a[i], a[a[i][0]]);
            i = -1;
            ans++;
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (j != 0) ok &= a[i][j] == i * c + j + 1;
            else ok &= a[i][j] == i;
        }
    }
    if (ok) {
        cout << ans << '\n';
    }
    else {
        cout << "*\n";
    }
}


int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}
