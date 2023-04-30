#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(4);
    vector<int> divs;
    for (auto &u : a) {
        cin >> u;
    }
    int y = a[2];
    for (int i = 1; i*i <= y; i++) {
        if (y % i == 0) {
            divs.emplace_back(i);
            divs.emplace_back(y / i);
        }
    }
    long long n = a[0];
    sort(divs.begin(), divs.end());
    for (auto u : divs) {
        if (u % n == 0 && u % a[1] && a[3] % u) {
            cout << u << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}





