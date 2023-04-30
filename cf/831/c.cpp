#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
    for(auto &u : a) cin >> u;
    sor(a);
    vector<ii> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = ii(max(abs(a[i]-a[0]), abs(a[i]-a[n-1])), (i==0 ? (abs(a[i]-a[i+1])) : i==n-1 ? (abs(a[i]-a[i-1])) : max(abs(a[i]-a[i+1]),abs(a[i]-a[i-1]))));
    }
    int anss = 0;
    for(int i = 0; i < n; i++){
        anss = max(anss, ans[i].fst + ans[i].snd);
    }
    cout << anss << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



