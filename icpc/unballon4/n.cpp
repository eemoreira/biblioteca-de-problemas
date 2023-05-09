#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int maxn = 1e7 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ii> pos, neg;
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        if (v > 0) pos.emplace_back(l, r);
        else neg.emplace_back(l, r);
    }
    sort(pos.begin(), pos.end(), [&](ii a, ii b){return a.second > b.second;});
    sort(neg.begin(), neg.end());
    vector<ii> a, b;
    for (int i = 0; i < (int)pos.size(); i++) {
        int t = i + 1;
        while (t < (int)pos.size() && pos[t].second >= pos[t - 1].first) {
            pos[t].first = min(pos[t].first, pos[t - 1].first);
            t++;
        }
        a.emplace_back(pos[t - 1].first, pos[i].second);
        i = t - 1;
    }
    for (int i = 0; i < (int)neg.size(); i++) {
        int t = i + 1;
        while (t < (int)neg.size() && neg[t].first <= neg[t - 1].second) {
            neg[t].second = max(neg[t].second, neg[t - 1].second);
            t++;
        }
        b.emplace_back(neg[i].first, neg[t - 1].second);
        i = t - 1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    int x = 0, y = 0;
    for (int i = 0; i < maxn; i++) {
        if (x < (int)a.size() && a[x].first + i >= 0) {
            x++;
        }
        if (y < (int)b.size() && b[y].second - i <= 0) {
            y++;
        }
        if (y < (int)b.size() && b[y].first - i <= 0 && b[y].second > 0) {
            ans++;
        }
        else if (x < (int)a.size() && a[x].second + i >= 0 && a[x].first + i < 0) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    solve();
}

