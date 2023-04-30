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

const int mx = 5e5 + 5, lg = 19;
int n2[mx];
int sparseMax[lg][mx], sparseMin[lg][mx];


int getMax(int l, int r){
  int last = n2[r-l];
  return max(sparseMax[last][l], sparseMax[last][r - (1 << last)]);
}
int getMin(int l, int r){
  int last = n2[r-l];
  return min(sparseMin[last][l], sparseMin[last][r - (1 << last)]);
}

void solve(){
  int n; cin >> n;
  vi a(n+1);
  vi pos(n+10);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    pos[a[i]] = i;
    sparseMax[0][i] = sparseMin[0][i] = a[i];
  }
  for(int i = 0; i < lg-1; i++){
    for(int j = 0; j + (1 << (i+1)) <= n;  j++){
      sparseMax[i+1][j] = max(sparseMax[i][j], sparseMax[i][j + (1 << i)]);
      sparseMin[i+1][j] = min(sparseMin[i][j], sparseMin[i][j + (1 << i)]);
    }
  }
  vi nextSmaller(n+1), nextBigger(n+1);
  vi sr(n+1);
  sr[0] = n;
  int sz = 0;
  a[n] = n+1;
  for(int i = n-1; i >= 0; i--){
    while(a[sr[sz]] < a[i]) sz--;
    nextBigger[i] = sr[sz];
    sr[++sz] = i;
  }
  sz = 0;
  a[n] = -1;
  for(int i = n-1; i >= 0; i--){
    while(a[sr[sz]] > a[i]) sz--;
    nextSmaller[i] = sr[sz];
    sr[++sz] = i;
  }
  int p = 0;
  int ans = 0;
  while(p < n-1){
    ans++;
    if(a[p] < a[p+1]){
      int newp = nextSmaller[p];
      if(newp==p)newp=n-1;
      /* cout << "max: " << getMax(p+1,newp) << '\n'; */
      p = pos[getMax(p+1,newp)];
    }
    else{
      int newp = nextBigger[p];
      if(newp==p)newp=n-1;
      /* cout << "min: " << getMin(p+1,newp) << '\n'; */
      p = pos[getMin(p+1,newp)];
    }
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 2; i < mx; i++){
    n2[i] = n2[i/2] + 1;
  }
  int tt; cin >> tt;
  while(tt--)solve();
  return 0;
}


