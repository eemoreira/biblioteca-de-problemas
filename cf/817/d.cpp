#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
typedef long long ll;
 
void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll st=0,e=n-1;
    vector<int> sum(n);
    ll ans=0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') sum[i] = i;
        if(s[i] == 'R') sum[i] = n-1-i;
        ans+=sum[i];
    }
    int count = 0;
    while(st < e){
        if(s[st] == 'L' || s[e] == 'R'){
            if(s[st] == 'L'){
                ans-=st;
                ans+=(n-1-st);
                s[st] = 'R';
                count++;
                cout << ans << ' ';
            }
            else{
                ans-=(n-1-e);
                ans+=e;
                count++;
                s[e] = 'L';
                cout << ans << ' ';
            }
        }   
        else{
            st++;e--;
        }
    }   
    int k = n - count;
    for(int i = 0; i < k; i++) cout << ans << ' ';
    cout << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}
 
