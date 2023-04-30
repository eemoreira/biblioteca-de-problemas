#include <bits/stdc++.h>

using namespace std;

/* stop freaking out pls */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(3);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    if (a[0] == a[1] || a[1] == a[2]) {
        cout << "S\n";
    }
    else if (a[0] + a[1] == a[2]) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }
}





