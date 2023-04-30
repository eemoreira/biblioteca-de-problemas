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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> a(n);
    multiset<ii> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        pq.emplace(a[i].second, a[i].first);
    }
    int ans = 0;
    while (!pq.empty()) {
        int f = pq.begin()->first;
        ans++;
        auto it = pq.begin();
        while (!pq.empty() && it->second < f) {
            it = pq.erase(it);
        }
    }
    cout << ans << '\n';
}





