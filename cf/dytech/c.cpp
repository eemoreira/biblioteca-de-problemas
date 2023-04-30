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
int x,y;
int n;
ii a[3];

void solve(){
    cin >> n;
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        a[i] = ii(x,y);
    }
    cin >> x >> y;
    for(int i = 0; i < 3; i++){
        if(x == a[i].fst && y == a[i].snd){
            cout << "YES\n";
            return;
        }
    }
    ii mid = ii(a[0].fst == a[1].fst ? a[0].fst : a[2].fst, a[0].snd == a[1].snd ? a[0].snd : a[2].snd);
    if(mid == ii(1,1) || mid == ii(1,n) || mid == ii(n,1) || mid == ii(n,n)){
        if(x == mid.fst || y == mid.snd) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    if((mid.fst + mid.snd)%2 == (x+y)%2) cout << (x%2 == mid.fst%2 ? "YES\n" : "NO\n");
    else cout << "YES\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



