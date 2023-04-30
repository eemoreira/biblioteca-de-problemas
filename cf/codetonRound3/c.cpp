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
    string a,b; cin >> a >> b;
    bool same = true;
    bool inv = true;
    for(int i = 0; i < n; i++){
        same &= (a[i] == b[i]);
        inv &= (a[i] != b[i]);
    }
    if(!same && !inv) cout << "NO\n";
    else{
        vii ans;
        if(inv){
            ans.eb(1,n);
            a = b;
        }
        vi f(n+1);
        for(int i = 0; i < n; i++){
            if(a[i] == '1'){
                if(i == n-1){
                    ans.eb(1,n);
                    ans.eb(1,n-1);
                }
                else{
                    f[i+2]++;
                    f[i+1]++;
                }
            }
        }
        for(int i = 1; i <= n; i++) if(f[i]&1) ans.eb(i,n);
        cout << "YES\n" << (int)ans.size() << '\n';
        for(auto u : ans) cout << u.fst << ' ' << u.snd << '\n';
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



