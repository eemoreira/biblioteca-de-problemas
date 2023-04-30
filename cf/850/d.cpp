#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int gt(char c) {
  if (c == 'i') return 0;
  if (c == 'n') return 1;
  if (c == 'w') return 2;
  return -1;
}

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  map<string, set<int>> f;
  string w = "win";
  sort(w.begin(), w.end());
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sort(a[i].begin(), a[i].end());
    if (a[i] != w) {
      f[a[i]].emplace(i);
    }
  }
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++) {
    vector<int> q(3);
    for (auto u : a[i]) q[gt(u)]++;
    for (auto u : w) {
      if (q[gt(u)] > 1) {
        vector<string> now(6,"");
        char c1 = w[(gt(u)+1)%3];
        char c2 = w[(gt(u)+2)%3];
        now[0] = string(3, c1);
        now[1] = string(3, c2);
        now[2] = c1;
        now[2] += string(2, c2);
        now[3] = c2;
        now[3] += string(2, c1);
        now[4] = u;
        now[4] += string(2, c1);
        now[5] = u;
        now[5] += string(2, c2);
        bool ok = false;
        dbg(now);
        for (auto &x : now) {
          if (ok) {
            break;
          }
          sort(x.begin(), x.end());
          sort(a[i].begin(), a[i].end());
          vector<int> q2(3);
          dbg(x);
          for (auto y : x) {
            q2[gt(y)]++;
          }
          for (int j = 0; j < 3; j++) {
            if (!f[x].empty() && !q[gt(x[j])] && q2[gt(x[j])] > 1) {
              int id = *f[x].begin();
              f[x].erase(f[x].begin());
              vector<int> t = {i+1,u,id+1,x[j]};
              ans.emplace_back(t);
              for (int k = 0; k < 3; k++) {
                if (a[id][k] == x[j]) {
                  a[id][k] = u;
                  break;
                }
              }
              f[a[i]].erase(i);
              for (int k = 0; k < 3; k++) {
                if (a[i][k] == u) {
                  a[i][k] = x[j];
                  break;
                }
              }
              sort(a[i].begin(), a[i].end());
              sort(a[id].begin(), a[id].end());
              f[a[i]].emplace(i);
              f[a[id]].emplace(id);
              i--;
              ok = true;
              break;
            }
          }
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i][0] << ' ' << char(ans[i][1]) << ' ' << ans[i][2] << ' ' << char(ans[i][3]) << '\n';
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





