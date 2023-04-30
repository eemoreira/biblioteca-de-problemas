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

int ok2321 = 0;
const int mod = 1e9 + 7, mx = 2e5 + 5; // 998244353
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
  int n,m; cin >> n >> m;
  int a[mx];
  for(int i = 0; i < m; i++){
    cin >> a[i];
  }
  int q; cin >> q;
  SegmentTreeMax segma(a,a+m);
  while(q--){
    int xi,yi,xf,yf,k; cin >> xi >> yi >> xf >> yf >> k;
    xi--;xf--;yi--;yf--;
    int l = yi, r = yf;
    if(l > r) swap(l,r);
    int need = segma.query(l,r);
    if(yi%k != yf%k || xi%k != xf%k){
      cout << "NO\n";
      continue;
    }
    int ma = (n - xi - 1)/k;
    ma *= k;
    ma += xi;
    cout << (need <= ma ? "YES\n" : "NO\n");
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



