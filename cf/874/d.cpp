#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef pair<int,int> ii;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

vector<int> ap(vector<int>& a, int j) {
  int n = a.size();
  vector<int> ans;
  for (int i = n - 1; i >= j; i--) ans.emplace_back(a[i]);
  for (int i = 0; i < j; i++) ans.emplace_back(a[i]);
  return ans;
}

vector<int> ap2(vector<int>& a, int j, int k) {
  int n = a.size();
  vector<int> ans;
  vector<int> x;
  for (int i = k; i <= j; i++) {
    x.emplace_back(a[i]);
  }
  reverse(x.begin(), x.end());
  for (int i = j + 1; i < n; i++) ans.emplace_back(a[i]);
  for (auto u : x) ans.emplace_back(u);
  for (int i = 0; i < k; i++) ans.emplace_back(a[i]);
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int j = pos[n] == 0 ? pos[n - 1] : pos[n];
  vector<int> ans(n, 0);
  if (j == n - 1) {
    for (int i = n - 1; i >= 0; i--) {
      ans = max(ans, ap(a, i));
    }
  }
  else {
    for (int i = j - 1; i >= 0; i--) {
      ans = max(ans, ap2(a, j - 1, i));
    }
  }
  for (auto u : ans) {
    cout << u << ' ';
  }
  cout << '\n';
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





