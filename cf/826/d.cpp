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

const int mx = 3e5 + 5;
void solve(){
    int n; cin >> n;
    int a[mx];
    for(int i = 0; i < n; i++) cin >> a[i];
    int t = n;
    ll ans = 0;
    int log = 0;
    while(t) t >>= 1, log++;
    for(int i = 1; i <= log; i++){
        for(int k = (1 << (i-1)) ; k < n; k += (1 << i)){
            if(a[k - (1 << (i-1))] > a[k]){
                swap(a[k - (1 << (i-1))], a[k]);
                ans++;
            }
            if(a[k - (1 << (i-1))] != a[k] - (1 << (i-1))){
                cout << - 1 << endl;
                return;
            }
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



