#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

void solve() {
    int n;
    cin >> n;
    multiset<int> neg, a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            neg.emplace(x);
        }
        else {
            a.emplace(x);
        }
    }
    int mx = *a.rbegin();
    int mn = *neg.begin();
    vector<int> ans;
    long long now = 0;
    dbg(mx, mn);
    while (!a.empty() || !neg.empty()) {
        if (a.empty()) {
            while (!neg.empty()) {
                ans.emplace_back(*neg.begin());
                neg.erase(neg.begin());
            }
            break;
        }
        else if (neg.empty()) {
            while (!a.empty()) {
                ans.emplace_back(*a.begin());
                a.erase(a.begin());
            }
            break;
        }
        if (now + *a.rbegin() < mx - mn) {
            ans.emplace_back(*a.rbegin());
            now += *a.rbegin();
            a.erase(--a.end());
        }
        else {
            ans.emplace_back(*neg.begin());
            now += *neg.begin();
            neg.erase(neg.begin());
        }
        if (now < 0) now = 0;
    }
    dbg(ans);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + ans[i] < 0) sum = 0;
        else sum += ans[i];
        if (sum >= mx - mn) {
            cout << "no\n" << '\n';
            return;
        }
    }
    cout << "yes\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}





