#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
void solve() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  string s;
  cin >> s;
  int n = s.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += s[i] == 'A';
  }
  if (sum != a + c + d) {
    cout << "no\n";
    return;
  }
  int ans = 0;
  vector<int> A, B;
  int ptr = 0;
  while (ptr < n) {
    int r = ptr;
    while (r < n-1 && s[r+1] != s[r]) {
      r++;
    }
    int t = r - ptr + 1;
    if (t > 1) {
      if (t & 1) {
        ans += t/2;
      } 
      else {
        ans += t/2 - 1;
        if (s[ptr] == 'A') {
          A.emplace_back(t/2);
        } 
        else {
          B.emplace_back(t/2);
        }
      }
    }
    dbg(ptr, r, t, ans);
    ptr = r + 1;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  dbg(ans, A, B);
  int k = c + d;
  for (auto u : A) {
    if (c >= u) {
      ans++;
      c -= u;
    }
  }
  for (auto u : B) {
    if (d >= u) {
      ans++;
      d -= u;
    }
  }
  dbg(ans, k);
  cout << (ans >= k ? "yes\n" : "no\n");
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





