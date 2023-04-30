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

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u : a) cin >> u;
    ll ones = 0;
    ll inv = 0;
    for(int i = 0; i < n; i++){
        ones += a[i];
        if(!a[i]){
            inv += ones;
        }
    }
    int ind = 0;
    for(int i = 0; i < n; i++){
        if(a[i])ind = i;
    }
    vi b(n);
    for(int i = 0; i < n; i++) b[i] = a[i];
    b[ind] = 0;
    ones = 0;
    ll inv2 = 0;
    for(int i = 0; i < n; i++){
        ones += b[i];
        if(!b[i]){
            inv2 += ones;
        }
    }
    vi c(n);
    for(int i = 0; i < n; i++) c[i] = a[i];
    int indd = 0;
    for(int i = 0;i < n; i++) if(!a[i]){
        indd = i;
        break;
    }
    ll inv3 = 0;
    ones = 0;
    c[indd] = 1;
    for(int i = 0; i < n; i++){
        ones += c[i];
        if(!c[i]){
            inv3 += ones;
        }
    }
    cout << max(max(inv3,inv),inv2)  << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



