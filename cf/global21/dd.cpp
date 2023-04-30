#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqmin;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back
#define inf 1e9+5
#define linf 1e17+5

#define comp(a,b) min(a,b)

class SegmentTreeMin{
  vi a;
  int n;
  public:
  SegmentTreeMin(int* st, int* end){
    int size = int(end-st);
    for(n = 1; n <= size; n <<= 1);
    a.assign((n << 1), inf);
    for(int i = 0; i < size; i++) a[i+n] = st[i];
    for(int i = n + size; i > 1; i--){
      a[i>>1] = min(a[i>>1],a[i]);
    }
  }
  void update(int i, int x){
    a[i+=n] = x; 
    for(i >>= 1; i; i >>= 1){
      a[i] = min(a[i<<1],a[1 + (i<<1)]);
    }
  }
  int query(int l, int r){
    int ans = inf;
    for(l+=n, r+=n+1; l < r; l>>=1,r >>= 1){
      if(l&1) ans = min(ans, a[l++]);
      if(r&1) ans = min(ans, a[--r]);
    }
    return ans;
  }
};

class SegmentTreeMax{
  vi a;
  int n;
  public:
  SegmentTreeMax(int* st, int* end){
    int size = int(end-st);
    for(n = 1; n <= size; n <<= 1);
    a.assign((n << 1), -inf);
    for(int i = 0; i < size; i++) a[i+n] = st[i];
    for(int i = n + size; i > 1; i--){
      a[i>>1] = max(a[i>>1],a[i]);
    }
  }
  void update(int i, int x){
    a[i+=n] = x; 
    for(i >>= 1; i; i >>= 1){
      a[i] = max(a[i<<1],a[1 + (i<<1)]);
    }
  }
  int query(int l, int r){
    int ans = -inf;
    for(l+=n, r+=n+1; l < r; l>>=1,r >>= 1){
      if(l&1) ans = max(ans, a[l++]);
      if(r&1) ans = max(ans, a[--r]);
    }
    return ans;
  }
};

void solve(){
  int n; cin >> n;
  int st[250008];
  vi pos(n+10);
  for(int i = 0; i < n; i++){
    cin >> st[i];
    pos[st[i]] = i;
  }
  SegmentTreeMin segmi(st,st+n);
  SegmentTreeMax segma(st,st+n);
  vi nextSmaller(n+1), nextBigger(n+1);
  vi sr(n+1);
  sr[0] = n;
  int sz = 0;
  st[n] = n+1;
  for(int i = n-1; i >= 0; i--){
    while(st[sr[sz]] < st[i]) sz--;
    nextBigger[i] = sr[sz];
    sr[++sz] = i;
  }
  sz = 0;
  st[n] = -1;
  for(int i = n-1; i >= 0; i--){
    while(st[sr[sz]] > st[i]) sz--;
    nextSmaller[i] = sr[sz];
    sr[++sz] = i;
  }
  int p = 0;
  int ans = 0;
  while(p < n-1){
    ans++;
    if(st[p] < st[p+1]){
      int newp = nextSmaller[p];
      if(newp==p)newp=n-1;
      p = pos[segma.query(p,newp)];
    }
    else{
      int newp = nextBigger[p];
      if(newp==p)newp=n-1;
      p = pos[segmi.query(p,newp)];
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--)solve();
  return 0;
}


