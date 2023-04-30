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
const int mx = 2e5 + 5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vi a(n);
    for(auto &u : a ) cin >> u;
    map<int,int> ch;
    for(int i = 1; i < n; i++) if(s[i] == '1' && s[i-1] == '0') ch[i] = 1;

    vi pf(n+1);
    pf[0] = 0;
    for(int i = 1; i <= n; i++) pf[i] = pf[i-1] + a[i-1];

    int last = 0;
    int ind = 0;
    ll ans = 0;

    for(int i = 0; i < n; i++) if(s[i]=='1') last = i;
    int c = 0;
    while(s[c] == '1'){
        ans += a[c];
        c++;
    }
    ind = c;
    /* for(int i = 0; i <= n; i++) cout << pf[i] << ' '; */
    /* cout << endl; */
    /* cout << "last: " << last << endl; */
    s += '0';
    for(int i = c+1; i <= last && ind <= last; i++){
        if(s[i]=='0')ind = i;
        else if(!ch[i]){
            /* cout << pf[ind] << ' ' << pf[i] << endl; */
            if(pf[i] - pf[ind] > pf[i+1] - pf[ind+1]){
                s[i] = '0';
                ch[i+1] = 1;
                ans += pf[i] - pf[ind];
                ind = i;
            }
            else if(s[i+1] == '0') ans += (pf[i+1] - pf[ind+1]);
        }
        else{
            /* cout << a[i] << endl; */
            if(a[i-1] > a[i]){
                if(s[i] == '1') ch[i+1] = 1;
                s[i] = '0';
                ind = i;
                ans += a[i-1];
            }
            else if(s[i+1] == '0') ans += a[i];
        }
    }
    /* for(auto [u,w] : ch) cout << u << ' ' << w << endl; */
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



