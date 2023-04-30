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

int get(int n, int step, int first , int last, int dir){
    if(n == 1) return first;
    if((n&1)) return get(n/2 + 1, step*2 ,first, last, !dir);
    else{
        if(dir) return get(n/2, step*2 , first + step/2, last, !dir);
        else return get(n/2, step*2, first, last - step/2, !dir);
    }
}

void solve(){
    int n; cin >> n;
    cout << get(n,2,1,n,0) << endl;
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}




