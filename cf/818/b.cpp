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
  int n,k,r,c; cin >> n >> k >> r >> c;
  int cnt = 0;
  char g[505][505];
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = '.';
  g[r-1][c-1] = 'X';
  for(int x = r-1, y = c-1; x >= 0; x--){
    for(int i = y; i < n; i+=k) g[x][i] = 'X';
    for(int i = y; i >= 0; i-=k) g[x][i] = 'X';
    y++;
    if(y >= n) y = 0;
  }
  for(int x = r-1, y = c-1; x < n; x++){
    for(int i = y; i < n; i+=k) g[x][i] = 'X';
    for(int i = y; i >= 0; i-=k) g[x][i] = 'X';
    y--;
    if(y < 0) y = n-1;
  }
  for(int i = 0; i < n; i++){
    for(int j =0 ; j < n; j++){
      cout << g[i][j];
    }
    cout << '\n';
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



