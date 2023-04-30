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
    vi a(n);
    for(auto &u: a) cin >> u;
    int g = a[0];
    if(n==1){
        if(a[0]==1) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    for(int i = 1; i < n; i++){
        g = gcd(g,a[i]);
    }
    if(g==1){
        cout << 0 << endl;
        return;
    }
    int ans = n;
    for(int i = 1; i < n; i++){
        int cnt = 0;
        int gc = gcd(a[i], i+1);
        int ans2 = n - i;
        int check = gc;
        for(int d = 0; d < n; d++){
            if(d==i)continue;
            check = gcd(check, a[d]);
        }
        if(check==1) ans = min(ans2,ans);
        for(int k = n-1; cnt < i && k > i ; k--){
            cnt++;
            int anss = ans2;
            anss+=n-k;
            gc = gcd(gc,gcd(a[k],k+1));
            if(gc ==1) ans = min(anss,ans);
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



