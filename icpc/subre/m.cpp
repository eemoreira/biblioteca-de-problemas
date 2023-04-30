#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 5;

vector<vector<int>> filho(mx);
map<int,int> morreu;
vector<pair<int,int>> q(mx);
int n, filhos=1,cq,pr;

void dfs(int r){ 
    if(!morreu[r]){
        if(pr) {
            cout << r << endl;
            pr = 0;
        }
        while(cq < n){
            auto [u,w] = q[cq];
            if(u==1){
                filhos++;
                filho[w].push_back(filhos);
            }
            if(u==2 && w == r){
                pr = 1;                
                morreu[w] = 1;
                cq++;
                break;
            }
            else if(u==2){
                morreu[w] = 1;
                cout << r << endl;
            }
            cq++;
        }
    }
    if(filho[r].size()){
       for(int i = 0; i < filho[r].size(); i++){
            dfs(filho[r][i]);
        }
    }
}
void solve(){
    cin >> n;
    
    for(int i = 0; i  < n; i ++){
        int t,x; cin>> t >> x;
        q[i] = {t,x}; 
    }
    dfs(1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

