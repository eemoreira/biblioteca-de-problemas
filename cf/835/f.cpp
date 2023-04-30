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
    int n; ll c,d; cin >> n >> c >> d;
    vi a(n);
    for(auto &u : a) cin >> u;
    sor(a);
    reverse(all(a));
    int l = 0, r = d;
    ll ans = -1;
    ll aa = 0;
    for(int i = 0; i < min(d,(ll)n); i++) aa += a[i];
    if(aa >= c){
        cout << "Infinity\n";
        return;
    }
    while(l <= r){
        int mid = (l+r)/2;
        ll all = 0;
        int t = d;
        for(int i = 0; i < min(mid+1,n); i++){
            /* cout << "i: " << a[i] << ' ' << mid + i << ' ' << (t%(mid+i)) << '\n'; */
            /* cout << ((t/(mid)) + (t%(mid) != 0)) << '\n'; */
            all += (ll) a[i] * ((t/(mid+1)) + (t%(mid+1) != 0));
            t--;
        }
        /* cout << "mid: " << mid << " all: " << all << '\n'; */
        if(all >= c){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    if(ans==-1) cout << "Impossible\n";
    else cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



