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

/* stop freaking out pls */

long long mul(long long a, long long b, long long m) {
  long long ret = a*b - ((long long)((long double)1/m*a*b+0.5)*m);
  return ret < 0 ? ret+m : ret;
}

long long pow(long long x, long long y, long long m) {
  if (!y) return 1LL;
  long long ans = pow(mul(x, x, m), y/2, m);
  return y%2 ? mul(x, ans, m) : ans;
}

bool prime(long long n) {
  if (n < 2) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0) return 0;

  long long r = __builtin_ctzll(n - 1), d = n >> r;
  for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
    long long x = pow(a, d, n);
    if (x == 1 or x == n - 1 or a % n == 0) continue;

    for (int j = 0; j < r - 1; j++) {
      x = mul(x, x, n);
      if (x == n - 1) break;
    }
    if (x != n - 1) return 0;
  }
  return 1;
}

long long rho(long long n) {
  if (n == 1 || prime(n)) return n;
  auto f = [n](long long x) {return mul(x, x, n) + 1;};

  long long x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
  while (t % 40 != 0 or gcd(prd, n) == 1) {
    if (x==y) x = ++x0, y = f(x);
    q = mul(prd, abs(x-y), n);
    if (q != 0) prd = q;
    x = f(x), y = f(f(y)), t++;
  }
  return gcd(prd, n);
}

vector<long long> factorize(long long n) {
  if (n == 1) return {};
  if (prime(n)) return {n};
  long long d = rho(n);
  vector<long long> l = factorize(d), r = factorize(n / d);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}
void solve() {
  long long a,b,k;
  cin >> a >> b >> k;
  int mx = 0;
  map<int,int> fa,fb;
  int check = 0;
  for (auto u : factorize(a)) {
    check++;
    fa[u]++;
  }
  for (auto u : factorize(b)) {
    check++;
    fb[u]++;
  }
  dbg(fa,fb);
  dbg(check);
  if (k > check) {
    cout << "no\n";
    return;
  }
  if (k == 1) {
    bool oka = true;
    for (auto u : fa) {
      if (fb[u.first] < u.second) {
        oka = false;
      }
    }
    bool okb = true;
    for (auto u : fb) {
      if (fa[u.first] < u.second) {
        okb = false;
      }
    }
    if (a == b || (!oka && !okb)) {
      cout << "no\n";
    }
    else {
      cout << "yes\n";
    }
  }
  else {
    cout << "yes\n";
  }
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




