#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* stop freaking out pls */
map<long long, int> f;
vector<pair<long long, int>> p;
vector<long long> a;

void getP(long long n) {
  for (int i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      n /= i;
      f[i]++;
    }
  }
  if (n > 1) {
    f[n]++;
  }
}

void Divs(int ptr, int nump, long long x) {
  dbg(ptr,nump,x);
  if (ptr == nump) {
    cerr << "pushback -> " << x << '\n';
    a.emplace_back(x);
    return;
  }
  for (int i = 0; i <= p[ptr].second; i++) {
    Divs(ptr+1, nump, x);
    x *= p[ptr].first;
  }
}

void solve(){
  long long n,m1,m2;
  cin >> n >> m1 >> m2;
  f.clear();
  a.clear();
  p.clear();
  getP(m1);
  getP(m2);
  dbg(f);
  int nump = 0;
  for (auto u : f) {
    p.emplace_back(u);
    nump++;
  }
  dbg(p);
  Divs(0,nump,1);
  sort(a.begin(), a.end());
  dbg(a);
  int q = a.size();
  vector<long long> mx(q,1);
  for (int i = 0; i < q; i++) {
    if (a[i] <= n) {
      mx[i] = a[i];
    }
  }
  for (auto u : p) {
    int pr = u.first;
    int ptr = 0;
    for (int i = 0; i < q; i++) {
      if (a[i]%pr==0) {
        long long h = a[i]/pr;
        while (a[ptr] < h) {
          ptr++;
        }
        assert(ptr < q);
        mx[i] = max(mx[i], mx[ptr]);
      }
    }
  }
  long long ans = 0;
  long long cnt = 0;
  for (int i = 0; i < q; i++) {
    long long h = a[i]/mx[i];
    if (h <= n) {
      ans ^= h;
      cnt++;
    }
  }
  cout << cnt << ' ' << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
  }
}



