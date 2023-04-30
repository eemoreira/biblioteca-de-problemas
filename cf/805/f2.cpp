#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;
const int mx = 3e5 + 5;
int a[mx], b[mx];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    map<int,int> f;
    for(int i = 0; i < n; i++){
        while(!(a[i]&1) && a[i]) a[i] >>= 1;
        f[a[i]]++;
    }
    sort(b,b+n);
    reverse(b,b+n);
    bool ok = true;
    for(int i = 0; i < n; i++){
        bool db = false;
        while(b[i]){
            if(f[b[i]]){
                f[b[i]]--;
                db = true;
                break;
            }
            b[i] >>= 1;
        }
        ok &= db;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


