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

int ok2321 = 1;
const int mod = 1e9 + 7; // 998244353

void solve(){
  int n,m; cin >> n >> m;
  vll a(n);
  for(auto &u : a) cin >> u;
  int k; cin >> k;
  vll b(k);
  for(auto &u : b) cin >> u;
  vector<pair<ll,ll>> newa,newb;
  for(int i = 0; i < n; i++){
    int d = 1;
    while(a[i]%m==0){
      d *= m;
      a[i] /= m;
    }
    newa.eb(a[i],d);
  }
  for(int i = 0; i < k; i++){
    int d = 1;
    while(b[i]%m==0){
      d *= m;
      b[i] /= m;
    }
    newb.eb(b[i],d);
  }
  vector<pair<ll,ll>> ansa, ansb;
  /* for(auto u : newa) cout << u.fst << ' ' << u.snd << ", "; */
  /* cout << '\n'; */
  /* for(auto u : newb) cout << u.fst << ' ' << u.snd << ", "; */
  for(int i = 0; i < (int)newa.size();){
    pair<ll,ll> cur = mp(0,0);
    cur.fst = newa[i].fst;
    while(newa[i].fst == cur.fst){
      cur.snd += newa[i].snd;
      i++;
      if(i == (int)newa.size())break;
    }
    ansa.pb(cur);
  }
  for(int i = 0; i < (int)newb.size();){
    pair<ll,ll> cur = mp(0,0);
    cur.fst = newb[i].fst;
    while(newb[i].fst == cur.fst){
      cur.snd += newb[i].snd;
      i++;
      if(i == (int)newb.size())break;
    }
    ansb.pb(cur);
  }
  cout << (ansa == ansb ? "yes\n" : "no\n");
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



