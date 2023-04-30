#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  multiset<pair<int,int>, greater<pair<int,int>>> pq;
  for (int i = 0; i < n; i++) {
    pq.emplace(a[i],i);
  }
  while (!pq.empty()) {
    int i = pq.begin()->second;
    int v = pq.begin()->first;
    pq.erase(pq.begin());
    if (i > 0 && a[i-1] < v - m) {
      pair<int,int> now = {a[i-1],i-1};
      pq.erase(now);
      a[i-1] = v - m;
      pq.emplace(a[i-1],i-1);
    }
    if (i < n-1 && a[i+1] < v - m) {
      pair<int,int> now = {a[i+1],i+1};
      pq.erase(now);
      a[i+1] = v - m;
      pq.emplace(a[i+1],i+1);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i+1 == n];
  }
}





