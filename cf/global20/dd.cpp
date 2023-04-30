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
  vector<int> a(n), b(n);
  for (auto &u : a) {
    cin >> u;
  }
  for (auto &u : b) {
    cin >> u;
  }
  map<int, int> mapa; 
  bool dr = 0; 
  int it = n-1;
  for (int i = n-1; i >= 0; i--) {
    while (it > 0 && b[it-1] == b[it]) {
      it--; 
      mapa[b[it]]++; 
    } 
    dbg(it,i);
    if (a[i] != b[it]) {
      mapa[a[i]]--; 
      if (mapa[a[i]] < 0) dr = 1; 
    } 
    else it--; 
  } 
  cout << (dr ? "no\n" : "yes\n");
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





