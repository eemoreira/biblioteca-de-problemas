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
  string a,b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << '\n';
    return;
  }
  if (a == string(n, '0') || b == string(n, '0')) {
    cout << -1 << '\n';
    return;
  }
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    x[i] = a[i] - '0';
    y[i] = b[i] - '0';
  }
  int px = 0, py = 0;
  while (px < n && x[px] == 0) {
    px += 1;
  }
  while (py < n && y[py] == 0) {
    py += 1;
  }
  vector<int> ans;
  auto sft = [&](int v) {
    ans.emplace_back(-v);
    if (v > 0) {
      for (int i = n-1; i >= 0; i--) {
        if (i - v >= 0) {
          x[i] ^= x[i - v];
        }
      }
    }
    else {
      v = -v;
      for (int i = 0; i < n; i++) {
        if (i + v < n) {
          x[i] ^= x[i + v];
        }
      }
    }
  };
  if (px < py) {
    for (int i = px + 1; i < n; i++) {
      if (x[i] != y[i]) {
        sft(i - px);
      }
    }
    py = n - 1;
    while (y[py] == 0) { 
      py -= 1;
    }
    for (int i = py; i >= 0; i--) {
      if (x[i] != y[i]) {
        sft(i - py);
      }
    }
  }
  else {
    if (py < px) {
      sft(py - px);
    }
    for (int i = py + 1; i < n; i++) {
      if (x[i] != y[i]) {
        sft(i - py);
      }
    }
  }
  cout << ans.size() << '\n';
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






