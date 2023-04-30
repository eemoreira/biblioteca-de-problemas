#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

// 1 2 3 4 5 6
// 6 4 2 5 3 1

bool print(vector<int>x, vector<int>y) {
    vector<int> ans;
    while (!x.empty()) {
        ans.emplace_back(x.back());
        x.pop_back();
    }
    while (!y.empty()) {
        ans.emplace_back(y.back());
        y.pop_back();
    }
    for (int i = 1; i < (int)ans.size(); i++) {
        if (abs(ans[i] - ans[i - 1]) <= 1) return false;
    }
    for (auto u : ans) cout << u << ' ';
    cout << '\n';
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int r = n;
    vector<int> ans1, ans2;
    while (r > 0) {
        ans1.emplace_back(r);
        r -= 2;
    }
    r = n - 1;
    while (r > 0) {
        ans2.emplace_back(r);
        r -= 2;
    }
    if (print(ans1, ans2)) return 0;
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    dbg(ans1,ans2);
    if (print(ans1, ans2)) return 0;
    cout << "NO SOLUTION\n";
}





