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
int won[mx];

void solve(){
    int n,q; cin >> n >> q;
    vi a(n);
    for(auto &u : a) cin >> u;
    int ma = -1e9;
    int ind = -1;
    for(int i = 0 ; i < n; i++){
        if(a[i] > ma) ind = i;
        won[i] = 0;
        ma = max(a[i],ma);
    }
    int win = (a[0] > a[1] ? 0 : 1);
    won[win]++;
    for(int i = 2; i < n; i++){
        win = (a[win] > a[i] ? win : i);
        won[win]++;
    }
    while(q--){
        int qual, nr; cin >> qual >> nr;
        qual--;
        int rd = nr-qual+1;
        if(qual == 0) rd--;
        if(qual== ind){
            cout << max(0, rd) << endl;
        } 
        else{
            cout << max(0, (rd >= won[qual] ? won[qual] : rd)) << endl;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



