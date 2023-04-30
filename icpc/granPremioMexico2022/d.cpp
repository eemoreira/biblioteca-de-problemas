#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long,int> ,null_type,less<pair<long long,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ordered_set s;
  int n;
  cin >> n;
  vector<long long> num(n);
  int ptr = 0;
  while (n--) {
      int op;
      cin >> op;
      if (op == 1) {
          long long x;
          cin >> x;
          s.insert(make_pair(x, ptr));
          num[ptr] = x;
      }
      if (op == 2) {
          int i;
          cin >> i;
          i--;
          s.erase(make_pair(num[i], i));
      }
      if (op == 3) {
          long long x,i;
          cin >> i >> x;
          i--;
          s.erase(make_pair(num[i], i));
          num[i] += x;
          s.insert(make_pair(num[i], i));
      }
      if (op == 4) {
          int i;
          cin >> i;
          i--;
          cout << s.order_of_key(make_pair(num[i], -1e9)) << '\n';
      }
      ptr++;
  }
}





