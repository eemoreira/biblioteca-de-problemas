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

void solve(){
    int n; cin >> n;
    vi p(n);
    for(auto&u:p)cin>>u;
    vi t(n);
    for(auto&u:t)cin>>u;
    double s = 0, e = 1e8;
    double eps = 1e-6;
    while(e-s > eps){
        double fsthird = s + (e-s)/3;
        double sndthird = e - (e-s)/3;
        double f1 = -1e9;
        for(int i = 0; i < n; i++){
            f1 = max(f1, abs((double)p[i]-fsthird)+t[i]);
        }
        double f2 = -1e9;
        for(int i = 0; i < n; i++){
            f2 = max(f2, abs((double)p[i]-sndthird)+t[i]);
        }
        /* cout << s << ' ' << e << ' '; */
        /* cout << f1 << ' ' << f2 << endl; */
        if(f2 < f1) s = fsthird;
        else e = sndthird;
    }
    cout << setprecision(10) << fixed;
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



