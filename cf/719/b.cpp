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
    if(n <= 9){
        cout << n << endl;
        return;
    }
    int d = 1,keep=n,sla=10;
    int ans = 0;
    int c =0;
    while(n){
        c++;
        n/=10;
    }
    for(int i = 0; i < c-1; i++){
        d += sla;
        sla*=10;
    }
    sla /= 10;
    for(int i = 0; i < c-1; i++){
        ans+= keep/d;
        keep = sla;
        d-=sla;
        sla/=10;
    }
    cout << 9 + ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



