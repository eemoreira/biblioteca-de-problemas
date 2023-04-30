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
#define eb emplace_back

int ok2321 = 0;

void solve(){
    int n,k; cin >> n >> k;
    int ans=-1e9;
    vi a(n);
    for(auto&u:a)cin>>u;
    int ne=0,pos=0;
    for(auto u : a) ne+=(u==-1),pos+=(u==1);
    /* cout << ne << ' ' << pos << endl; */
    for(int i = 0; i < n; i++){
        int cneg=0,cpos=0;
        for(int l = i; l < n; l+=k){
           /* cout << l << ' '; */
           cneg+= (a[l] == -1);
           cpos+= (a[l] == 1);
        }
        for(int d = i-k; d>=0; d-=k){
            cneg+= (a[d] == -1);
            cpos+= (a[d] == 1);
        }
        ans = max(abs((ne-cneg) - (pos-cpos)),ans);
        /* cout << "ans: " << cneg << ' ' << cpos << ' ' << ans << endl; */
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



