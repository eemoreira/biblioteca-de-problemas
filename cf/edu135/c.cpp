#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    int n; cin >> n;
    priority_queue<int> pa,pb;
    map<int,int> tema,temb;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        pa.push(a);
        tema[a]++;
    }
    for(int i = 0; i < n; i++){
        int b; cin >> b;
        pb.push(b);
        temb[b]++;
    }
    int ans = 0;
    while(!pa.empty()){
        int fa=pa.top(),fb=pb.top();
        auto [u,w] = max(ii(fa,1),ii(fb,2));
        if(fa == fb){
            pa.pop();
            pb.pop();
            temb[fb]--;
            tema[fa]--;
            continue;
        }
        if(u==1)break;
        else if(w==1){
            pa.pop();
            tema[u]--;
            if(!temb[u]){
                pa.push((int)log10(u)+1);
                tema[(int)log10(u)+1]++;
                ans++;
            }
        }   
        else if(w==2){
            pb.pop();
            temb[u]--;
            if(!tema[u]){
                pb.push((int)log10(u)+1);
                temb[(int)log10(u)+1]++;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

