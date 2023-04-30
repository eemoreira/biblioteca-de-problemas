#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

template<typename T>
struct fenwick{
  vector<T> ft;
  fenwick(int n){
    ft.resize(n + 1); // 1 indexed
  }
  T rsq(int i){
    T sum = 0;
    for(; i; i -= (i & -i)){
      sum += ft[i];
    }
    return sum;
  }
  T rsq(int i,int k){
    return rsq(k) - rsq(i-1);
  }
  void update(int i, T v){
    for(; i < (int) ft.size() ; i += (i & -i)){
      ft[i] += v;
    }
  }
};


void solve() {
  string s;
  cin >> s;
  int w,q;
  cin >> w >> q;
  int n = s.size();
  vector<int> a(n);
  fenwick<int> fw(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
    fw.update(i+1, a[i]);
  }
  int sum = 0;
  for (int i = 0; i < w; i++) {
    sum += a[i];
  }
  vector<vector<int>> mod(9);
  mod[sum%9].emplace_back(0);
  for (int i = w; i < n; i++) {
    sum -= a[i-w];
    sum += a[i];
    mod[sum%9].emplace_back(i-w+1);
  }
  while (q--) {
    int l,r,k;
    cin >> l >> r >> k;
    int f = fw.rsq(l,r)%9;
    pair<int,int> ans = {1e9,1e9};
    for (int i = 0; i < 9; i++) {
      if (!mod[i].empty()) {
        int g = f * i % 9;
        int t = (k+9-g)%9;
        if (!mod[t].empty()) {
          if (mod[t][0] != mod[i][0]) {
            ans = min(ans, make_pair(mod[i][0], mod[t][0]));
          }
          else if ((int)mod[t].size() > 1) {
            ans = min(ans, make_pair(mod[i][0], mod[t][1]));
          }
        }
      }
    }
    if (ans != make_pair((int)1e9,(int)1e9)) {
      cout << ans.first+1 << ' ' << ans.second+1 << '\n';
    }
    else {
      cout << "-1 -1\n";
    }
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





