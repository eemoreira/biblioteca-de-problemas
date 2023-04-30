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
    a.pb(1e9+5);
    int cnt = 0;
    for(int l = 0; l < n; l++){
        if(l == 0){
            while(a[l+1] == a[l]){
                l++;
            }
        }
        else if(a[l-1] > a[l]){
            while(a[l+1] == a[l]){
                l++;
            }
        }
        else continue;
        if(l == n){
            cnt++;
        }
        else if(a[l+1] > a[l]){
            cnt++;
        }
    }
    cout << (cnt == 1 ? "YES\n" : "NO\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



