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
vector<int> next_big(vector<int>& a) {
  vector<int> stk;
  int n = a.size();
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && a[stk.back()] < a[i]) {
      ans[stk.back()] = i;
      stk.pop_back();
    }
    stk.emplace_back(i);
  }
  return ans;
}

struct node {
  int mx, mn;
  node(int _mx, int _mn) : mx(_mx), mn(_mn) {
  }
  node() {
    mx = -1e9;
    mn = 1e9;
  }
};

const node neutral = node(-1e9, 1e9);

node comp(node a, node b) {
  return node(max(a.mx, b.mx), min(a.mn, b.mn));
}

const int MAX = 3e5 + 5;
int p2[MAX];
const int lg = 20;
vector<node> sparse[lg];
vector<node> a;
int n;

namespace sparseTable{
  void build(){
    for(int i = 0; i < lg; i++){
      sparse[i] = vector<node>(n, neutral);
    }
    for(int i = 0; i < n; i++){
      sparse[0][i] = a[i];
    }
    for(int i = 0; i < lg-1; i++){
      for(int j = 0; j + (1 << (i+1)) <= n;  j++){
        sparse[i+1][j] = comp(sparse[i][j], sparse[i][j + (1 << i)]);
      }
    }
  }
  node query(int l, int r){
    int last = p2[r-l];
    return comp(sparse[last][l], sparse[last][r - (1 << last)]);
  }
}

void solve() {
  cin >> n;
  a = vector<node>(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[i] = node(b[i], b[i]);
  }
  sparseTable::build();

  vector<int> nxtmax = next_big(b);

  for (int i = 0; i < n; i++) {
    if (nxtmax[i] == -1) nxtmax[i] = n;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll now = n - 1 - i;
    ans += now * (now + 1) / 2;
    ll it = nxtmax[i];
    ll r = 0;
    if (it < n) {
      int L = it, R = n - 1;
      while (L <= R) {
        int mid = (L + R) >> 1;
        if (sparseTable::query(it, mid + 1).mn > b[i]) {
          L = mid + 1;
          r = mid - it + 1;
        }
        else {
          R = mid - 1;
        }
      }
    }
    ll l = 1;
    int L = 0, R = i - 1;
    while (L <= R) {
      int mid = (L + R) >> 1;
      if (sparseTable::query(mid, R + 1).mx < b[i]) {
        l = i - mid + 1;
        R = mid - 1;
      }
      else {
        L = mid + 1;
      }
    }
    ans -= l * r;
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  p2[0] = p2[1] = 0;
  for (int i = 2; i < MAX; i++) {
    p2[i] = p2[i >> 1] + 1;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}





