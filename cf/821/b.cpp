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
    int n,x,y; cin >> n >> x >> y;
    if((x==0 && y==0) || (x!=0 && y!=0)){
        cout << -1 << endl;
        return;
    }
    if(x==0)swap(x,y);
    if((n-1-x)%x){
        cout << -1 << endl;
        return;
    }   
    int c = 0,d=1;
    for(int i = 2; i <= n; i++){
        if(c==x) c=0,d=i;
        cout << d << ' ';
        c++;
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



