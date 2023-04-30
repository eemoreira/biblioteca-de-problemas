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
    int a,b; cin >> a >> b;
    int ans1 =0;
    int t = a, d = b;
    while(a != b){
        int r = (a | b);
        if(r == b){
            ans1++; break;
        }
        a++;ans1++;
    }  
    int ans2=0;
    while(t != d){
        int r1 = (t | d);
        if(r1 == d){
            ans2++;break;
        }
        d++;ans2++;
    }
    cout << min(ans1,ans2)<< endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



