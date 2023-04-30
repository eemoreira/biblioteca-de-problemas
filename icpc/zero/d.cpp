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

void solve(){
    int t; cin >> t;
    string s; cin >> s;
    vector<string> alu;
    for(int i = 0; i < 5; i++){
        string tt; cin >> tt;
        alu.pb(tt);
    }
    map<int,double> pont;
    while(t--){
        vector<ii> query;
        for(int i = 0; i < 5; i++){
           int erros = 0;
           int ier = (int)alu[i].size()-1;
           int icerta = (int)s.size()-1;
           while(ier >= 0 && icerta >= 0){
                /* cout << i << ' '; */
                /* cout << alu[i][ier] << ' ' << ier << ' ' << s[icerta] << ' ' << icerta << endl; */ 
                if(alu[i][ier] == s[icerta]){
                    ier--; icerta--;
                    if(ier < 0 || icerta < 0){
                        erros++; break;
                    }
                }
                else{
                    if(alu[i][ier-1] == s[icerta]){
                        if(alu[i][ier-1] != s[icerta-1]){
                            erros++;
                            ier--;
                        }
                        else{
                            erros++;
                            ier--;
                            icerta--;
                        }
                    }
                    else if(alu[i][ier] == s[icerta-1]){
                        if(alu[i][ier-1] != s[icerta-1]){
                            erros++; ier--;
                        }
                        else{
                            erros++; ier--; icerta--;
                        }

                    }
                    else if(ier==0){
                        erros++; break;
                    }   
                    else{
                        ier--;icerta--;erros++;
                    }
                }
            }
            query.pb(ii(i+1, erros));
        }
        int mi = 1e9;
        for(auto u : query) cout << u.fst << ' ' << u.snd << endl;
        for(auto u : query) mi = min(u.snd,mi);
        cout << mi << endl;
        for(auto u : query){
            if(mi==0){
                if(u.snd==mi)pont[u.fst]++;
            }
            else{
                if(u.snd==mi)pont[u.fst]+=0.5;
            }
        }
    }
    double ma = -1e9;
    for(auto u : pont){
        ma = max(ma,u.snd);
        /* cout << u.fst << ' ' << u.snd << endl; */
    }
    cout << ma << endl;
    for(auto u : pont){
        if(u.snd == ma) cout << u.fst << ' ';
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



