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
const int mx = 2e5 + 5;
int a[mx], b[mx];


void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    unordered_map<int, int> f;
    for(int i = 0; i < n; i++) f[a[i]]++;
    int ans = 0;
    for(int i = 0; i < 32; i++){
        bool ok = true;
        for(int k = 0; k < n; k++){
            ok &= (b[k] == 0);
            if(b[k] == 0) continue;
            int t = b[k];
            while(t < (int)1e9 + 5){
                if(f[t]){
                    ans++;
                    f[t]--;
                    b[k] = 0;
                    break;
                }
                t <<= 1;
            }
            if(ans == n) ok = true;
            b[k] >>= 1;
        }
        if(ok) break;
    }
    cout << (ans==n ? "YES\n" : "NO\n");
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


