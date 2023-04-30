#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
typedef tuple<ll,ll,ll> i3;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back


int ok2321 = 1;
const ll mod = 998244353;
i3 dp[35][35];

ll get(i3 x){
    auto [a,b,c] = x;
    return (a%mod + b%mod + c%mod)%mod;
}

i3 go(int x, int y){
    if(dp[x][y] != i3(0,0,0)) return dp[x][y];
    if(x==0 || y==0) return dp[x][y] = i3(0,0,1);
    i3 v = i3(0,0,0);
    auto &[a,b,c] = v;
    a += get(go(x-1,y-1));
    if(x >= 2) a += get(go(x-2, y));
    if(y >= 2) b += get(go(x,y-2));
    auto [xa,ya,za] = go(x-1,y-1);
    a += ya;
    b += xa;
    c += za;
    return dp[x][y] = i3(a%mod, b%mod, c%mod);
}

void solve(){
    int n; cin >> n;
    auto[x,y,e] = go(n/2,n/2);
    /* for(int i = 0; i <= n/2; i++){ */
    /*     for(int k = 0; k <= n/2; k++){ */
    /*         auto [a,b,c] = dp[i][k]; */
    /*         cout << "{" << a << "," << b << "," << c << "} "; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
    cout << x << ' ' << y << ' ' << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



