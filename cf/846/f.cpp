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

const int MAX = 3e5+5;
namespace sieve {
  int lp[MAX+1], factor[MAX+1];
  vector <int> pr;
  void build() {
    for (int i = 2; i <= MAX; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= MAX; ++j) {
        lp[i * pr[j]] = pr[j];
        factor[i * pr[j]] = i;
        if (pr[j] == lp[i]) break;
      }
    }
  }
  vector<int> factorize(int x) {
    if (x < 2) return {};
    vector <int> v;
    for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
    return v;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve::build();
  vector<int> mu(MAX);
  for (int i = 2; i < MAX; i++) mu[i] = 2; 
  mu[1] = 1; 
  for (int i = 2; i < MAX; i++) {
    if (mu[i] == 2) {
      for (int j = i; j < MAX; j += i) {
        if (mu[j] == 2) {
          mu[j] = 1; 
        }
        if (mu[j]) {
          mu[j] *= j/i%i ? -1 : 0; 
        }
      } 
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  sort(a.begin(), a.end());
  dbg(a);
  vector<int> val(MAX,-1);
  vector<long long> d(MAX);
  for (int i = 0; i < n; i++) {
    val[a[i]] = i;
  }
  vector<long long> cnt(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j+=i) {
      if (val[j] >= 0) {
        cnt[i] += 1;
        if (val[j] > 0) {
          d[i] += val[j] - 1;
        }
      }
    }
  }
  vector<int> w;
  vector<pair<int,int>> p;
  function<void(int,int,int)> Divs = [&](int ptr, int size, int x) {
    if (ptr == size) {
      w.emplace_back(x);
      return;
    }
    for (int i = 0 ; i <= p[ptr].second; i++) {
      Divs(ptr+1,size,x);
      x *= p[ptr].first;
    }
  };
  vector<vector<int>> divs(n);
  for (int i = 0; i < n; i++) {
    w.clear();
    p.clear();
    map<int,int> f;
    for (auto u : sieve::factorize(a[i])) {
      f[u]++;
    }
    for (auto u : f) {
      p.emplace_back(u);
    }
    Divs(0,(int)p.size(),1);
    divs[i] = w;
  }
  long long ans = 0;
  for (int i = 0; i < n-2; i++) {
    for (auto u : divs[i]) {
      if (i > 1) {
        d[u] -= i-1;
      }
      cnt[u] -= 1;
    }
    for (auto u : divs[i]) {
      ans += mu[u] * (d[u] - i * cnt[u]);
    }
  }
  cout << ans << '\n';
}



