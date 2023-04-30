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
    vi a(n),b(n);
    for(auto &u : a) cin >> u;
    for(auto &u: b) cin >> u;
    int zero=0,um=0;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    for(auto u : a){
        zero += (u == 0);
        um += (u == 1);
    }
    int zero2=0,um2=0;
    for(auto u : b){
        zero2 += (u == 0);
        um2 += (u == 1);
    }
    if(zero == zero2 && um == um2){
        cout << 1 << endl;
        return;
    }
    int ans1 = 0;
    for(int i = 0; i < n; i++){
        ans1 += (a[i] != b[i]);
    }
    int ans = min(abs(um-um2),abs(zero-zero2));
    cout << min(1+ans,ans1) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



