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

int ok2321 = 1;
int n;
const int mx = 2e5 + 5;
vi a(mx);

int check(int mi){
    vi v(n);
    for(int i = 0; i < n; i++) v[i] = a[i];
    for(int i = n-1; i >=2 ; i--){
        if(v[i] < mi) return 0;
        int d = min(a[i],v[i]-mi)/3;
        v[i-1] += d;
        v[i-2] += 2*d;
    }
    /* cout << mi << endl; */
    /* for(auto u : v) cout << u << ' '; */
    /* cout << endl << endl; */
    int valid = (v[0] >= mi && v[1] >= mi);
    return valid;
}

void solve(){
    cin >> n;
    a.clear();
    for(int i = 0; i < n; i++)cin>>a[i];
    int mi = 1e9, ma= -mi;
    for(int i = 0 ; i < n ; i++){
        mi = min(a[i],mi);
        ma = max(a[i],ma);
    }
    int s = mi, e = ma;
    if(a[n-1] == mi){
        cout << mi << endl;
        return;
    }
    while(s < e){
        int md = s + (e-s+1)/2;
        if(check(md)) s=md;
        else e = md-1;
        
    }
    cout << s << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



