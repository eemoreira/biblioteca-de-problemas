#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u: a)cin >> u;
    vi pref(n+1);
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    int ans = n;
    for(int i = 1; i < n; i++){
       int cur = pref[i];
       int dif = cur;
       int ind = i;
       int res = i;
       int ok = 0;
       for(int k = i+1; k <= n; k++){
           /* cout << pref[k] << ' ' << cur << endl; */
           if(pref[k] - dif == cur){
               /* cout << "k: " << k << " i: " << i << ' '; */
               /* cout << "prefix : " << pref[k] << " cur : " << cur << endl; */
               ok = 1;
               res = max(res,k-ind);
               dif = pref[k];
               ind = k;
               /* cout << res << ' ' << cur << endl; */
           }
           else if(pref[k] - dif > cur || k == n){
               res = n;
               break;
           }
       }
       if(!ok) res = n;
       ans = min(ans,res);
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



