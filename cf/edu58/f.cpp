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
#define int long long 
 
int ok2321 = 0;
 
struct truck{
    ll s,f,c,r;
};
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
bool valid(int s, int f, int c, int r, ll mid, vector<ll>&a){
    int recharge = r;
    s--; f--;
    ll usin = mid;
    for(int k = s; k < f; k++){
        /* cout << a[k] << ' ' << a[k+1] << " usin : " << usin << " recharge : " << recharge << " dist : " << c * abs(a[k] - a[k+1]) << endl; */ 
        if(c * abs(a[k] - a[k+1]) > usin){
            if(recharge){
                recharge--;
                usin = mid;
            }
            else return false;
        }
        usin -= c * abs(a[k] - a[k+1]);
    }
    if(usin < 0) return false;
    else return true;
}
 
void solve(){
    int n,m; cin >> n >> m;
    vector<truck> trucks(m);
    vector<ll> a(n);
    for(auto &u : a) cin >> u;
    for(int i = 0; i < m; i++){
        int ss,ff,cc,rr; cin >> ss >> ff >> cc >> rr;
        trucks[i].s = ss;
        trucks[i].f = ff;
        trucks[i].c = cc;
        trucks[i].r = rr;
    }
    shuffle(trucks.begin(), trucks.end() , rng);
    ll s = 0, e = 1e18;
    while(s < e){
        ll mid = (s+e)/2;
        if(valid(trucks[0].s, trucks[0].f, trucks[0].c, trucks[0].r, mid, a)) e = mid;
        else s = mid + 1;
    }
    ll ans = s;
    for(int i = 1; i < m; i++){
        /* cout << trucks[i].s << ' ' << trucks[i].f << endl; */
        if(!valid(trucks[i].s, trucks[i].f, trucks[i].c, trucks[i].r, ans,a)){
            ll s = 0, e = 1e18;
            while(s < e){
                /* cout << "s : " << s << " e: " << e << endl; */
                ll mid = (s+e)/2;
                if(valid(trucks[i].s, trucks[i].f, trucks[i].c, trucks[i].r, mid, a)) e = mid;
                else s = mid + 1;
            }
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
}
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int tc=1;
  if(ok2321) cin >> tc;
  while(tc--) solve();
	return 0;
}
 
 
