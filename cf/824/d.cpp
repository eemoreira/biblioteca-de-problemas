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

int get(int a, int b){
    int x;
    if(a != 0 && b != 0) x=0;
    else if(a != 1 && b != 1) x=1;
    else if(a != 2 && b != 2) x = 2;
    return x;
}

void solve(){
    map<vi, int> have;
    int n,k; cin >> n >> k;
    vector<vi> a(n, vi (k));
    for(int i = 0; i < n; i++){
        for(int d = 0; d < k; d++){
            cin >> a[i][d]; 
        }
        have[a[i]] = i;
    }
    map<int , int> freq;
    map<vector<vi> , int> vis;
    vector<tuple<int,int,int>> conjs;
    for(int i = 0; i < n; i++){
        vi f = a[i];
        for(int d = 0; d < n; d++){
            if(d==i)continue;
            vi s = a[d];
            vi only;
            for(int h = 0; h < k; h++){
                if(s[h] == f[h]) only.pb(s[h]);
                else only.pb(get(s[h],f[h]));
            }
            vector<vi>tira;
            tira.pb(only);
            tira.pb(f);
            tira.pb(s);
            sor(tira);
            if(have.count(only) && !vis[tira]){
                vis[tira] = 1;
                conjs.eb(have[only],i,d);
            }
        }
    }
    ll ans = 0;
    for(auto [a,b,c] : conjs){
        freq[a]++;
        freq[b]++;
        freq[c]++;
    }
    for(auto [a,b,c] : conjs){
        cout << a << ' '  <<  b << ' ' << c << endl;
        cout << "freq: " << freq[a] << ' '  << freq[b] << ' ' << freq[c] << endl;
        ans += freq[a]-1;
        ans += freq[b]-1;
        ans += freq[c]-1;
    }
    cout << ans/2 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}




