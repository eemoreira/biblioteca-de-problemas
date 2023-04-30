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
const int mx = 105; 

void solve(){
    int n; cin >> n;
    string grid[mx];
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    ll anss = 0;

    for(int i = 0; i < n/2 ; i++){
        for(int d = 0; d < n/2 ; d++){
            int  o = 0;
            int cur = grid[i][d] - '0';
            int r = grid[d][n-i-1] - '0';
            int down = grid[n-i-1][n-d-1] - '0';
            int l = grid[n-d-1][i] - '0';
            o += cur + r + down + l;
            /* cout << "{"<<i<<' '<<d << "}" << ' ' << "{"<<d<<' '<<n-i-1 << "}" << "{"<<n-i-1<<' '<<n-d-1<< "}" << "{"<<n-i-1<<' '<<d << "}\n"; */
            anss += min(o,4-o);
            /* cout << cur << ' ' << r << ' ' << down << ' ' << l << " ans: " << anss << '\n'; */
        }
    }
    if(n&1){
        for(int i = 0; i < n/2; i++){
            int  o = 0;
            int cur = grid[i][n/2] - '0';
            int r = grid[n/2][n-i-1] - '0';
            int down = grid[n-i-1][n-n/2-1] - '0';
            int l = grid[n-n/2-1][i] - '0';
            o = cur + r + down + l;
            anss += min(o,4-o);
        }
    }
    cout << anss << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}


