const int mod = 1e9+7, MAX = 2e5 + 5;
/* const int mod = 998244353, MAX = 2e5 + 5; */
long long f[MAX];

inline long long add(long long a, long long b){
  long long ans = (a + b) % mod;
  if(ans < 0) ans += mod;
  return ans;
}
inline long long mul(long long a, long long b){
  long long ans = a * b % mod;
  if (ans < 0) ans += mod;
  return ans;
}
inline long long bpw(long long a, long long e){
  long long ans = 1;
  while(e){
    if(e&1){
      ans = mul(ans,a);
    }
    a = mul(a,a);
    e >>= 1;
  }
  return ans;
}
inline long long invMod(long long a){
  return bpw(a, mod-2);
}
inline long long dv(long long a, long long b){
  return mul(a, invMod(b));
}
inline long long nCr(int n, int r) {
  if(r > n) return 0;
  return dv(f[n], mul(f[n-r], f[r]));
}
