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

class fenwick{
private: 
    vi ft;
public:
    fenwick(int n){
        ft.assign(n + 1,0); // 1 indexed
    }
    int rsq(int i){
        int sum = 0;
        for(; i; i -= (i & -i)){
            sum += ft[i];
        }
        return sum;
    }
    int rsq(int i,int k){
        return rsq(k) - rsq(i-1);
    }
    void update(int i, int v){
        for(; i < (int) ft.size() ; i += (i & -i)){
            ft[i] += v;
        }
    }
};

int ok2321 = 0;

void solve(){
    int x,y; cin >> x >> y;
    int h,v; cin >> h >> v;
    fenwick hori(h);
    fenwick vert(v);
    vector<pair<ll,ll>> hr,vt;
    vector<ll> hrsnd,vtsnd;
    map<ll , int> indh,indv;
    for(int i = 0; i < h; i++){
        ll xi,xf; cin >> xi >> xf;
        hr.eb(xi,xf);
        hrsnd.pb(xf);
    }
    for(int i = 0; i < v; i++){
        ll yi,yf; cin >> yi >> yf;
        vt.eb(yi,yf);
        vtsnd.pb(yf);
    }
    sor(hrsnd); sor(vtsnd);
    for(int i = 0; i < h; i++) indh[hrsnd[i]] = i;
    for(int i = 0; i < v; i++) indv[vtsnd[i]] = i;
    ll ans = (ll) (h+1) * (v+1);
    sor(hr); sor(vt);
    for(int i = 0; i < h ; i++){
        hori.update(indh[hr[i].snd]+1, 1);
        ans += (ll) hori.rsq(indh[hr[i].snd]+2, h);
    }
    for(int i = 0; i < v; i++){
        vert.update(indv[vt[i].snd]+1, 1);
        ans += (ll) vert.rsq(indv[vt[i].snd]+2, v);
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



