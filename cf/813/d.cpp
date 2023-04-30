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
    int n,q; cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 1,r = 1e9;
    int ans = 0;
    if(q == n){
        cout << (int)1e9 << '\n';
        return;
    }
    vi b(n);
    while(l <= r){
        int mid = (l+r)>>1;
        for(int i = 0; i < n; i++) b[i] = a[i];
        int check = q;
        for(int i = 0; i < n; i++) if(b[i] < mid/2 + (mid%2)){
            check--;
            b[i] = 1e9;
        }
        bool ok = false;
        for(int i = 0; i < n-1; i++) ok |= (b[i] >= mid && b[i+1] >= mid);
        if(check < 0) r = mid - 1;
        else if(check >= 2){
            ans = mid;
            l = mid + 1;
        }
        else if(check == 1){
            for(int i = 0; i < n; i++) ok |= (b[i] >= mid);
            if(ok){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        else if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
        /* cout << "mid: " << mid << ' ' << ok << ' ' << check << '\n'; */
    }
    cout << (int) ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
  return 0;
}



