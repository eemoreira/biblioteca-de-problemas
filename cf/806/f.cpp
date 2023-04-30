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

void solve(){
    int n; cin >> n;
    vi a(n);
    for(auto &u : a) cin >> u;
    fenwick lt(n);
    vector<ii> possible;
    vector<ll> pf(n+1);
    pf[0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= i){
            pf[i+1] = pf[i] + 1;
        }
        else pf[i+1] = pf[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= i){
            if(a[i] > 0) ans += (ll) pf[a[i] - 1]; 
        }
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



