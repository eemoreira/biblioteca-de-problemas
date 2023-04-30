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
 
int ok2321 = 0;
const int mx = 1e5 + 15;
 
int person[mx];
 
void solve(){
    int n; cin >> n;
    int dir=0;
    int last=0;
    for(int i = 0; i < mx; i++) person[i] = -1;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        person[a] = b;
        last = a;
        if(!i) dir = b;
    }
    ll ans = 0;
    int cur = 0;
    for(int i = 0; i <= last; i++){
        /* cout << i << ' ' << person[i] << ' ' << dir << " cur: " << cur << " ans: " << ans << " last: " << last << endl; */
        if(person[i] == !dir){
            if(i - cur >= 10){
                /* cout << "trocou dir: " << i << endl; */
                dir = !dir;
                cur = i;
                last = max(cur + 10, last);
            }
            else{
                person[i] = dir;
                while(person[cur + 10] == dir) cur += 10;
                person[cur + 10] = !dir;
                /* cout << "boto 10 pra frente: " << cur+10 << endl; */
                last = max(last, cur + 10);
            }
            ans++;
        }
        else if(person[i] == -1){
            person[i] = dir;
            ans++;
        }
        else if(person[i] == dir){
            cur = i;
            last = max(last, cur + 10);
            ans++;
        }
    }
    /* for(int i = 0; i <= last; i++) cout << person[i] << ' '; */
    /* cout << endl; */
    cout << --ans << endl;
 
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}
 
