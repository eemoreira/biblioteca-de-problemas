#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int sum = 0;
    int notsum = 9;
    for (auto &u : a) {
        int now = 0;
        bool ok = true;
        for (auto &x : u) {
            cin >> x;
            if (!x) ok = false;
            now += x;
        }
        if (ok) sum = now;
        else notsum = now;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j]) {
                cout << sum - notsum << '\n';
                cout << i + 1 << '\n';
                cout << j + 1 << '\n';
            }
        }
    }
}





