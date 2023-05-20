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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, l;
  cin >> n >> l;
  multiset<ii> pq;
  vector<int> ans(n);
  int p = 0;
  int time = 0;
  for (int i = 0; i < l; i++) {
    int x;
    cin >> x;
    if (p < n) {
      pq.emplace(x, p);
      ans[p]++;
      p++;
    }
    else {
      int j = pq.begin()->second;
      ans[j]++;
      time = pq.begin()->first;
      pq.erase(pq.begin());
      pq.emplace(x + time, j);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << ans[i] << '\n';
  }
}





