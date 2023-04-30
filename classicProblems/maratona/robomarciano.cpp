#include <bits/stdc++.h>

const int MAX = 1000;

using namespace std;

void solve(){
    int xi,yi,xf,yf; cin >> xi >> yi >> xf >> yf;
    int n; cin >> n;
    deque<pair<int,int>> dq;
    dq.push_front(make_pair(xi,yi));
    vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0},{0,-1}};
    vector<pair<int,int>> vy(n);
    vector<pair<int,int>> vx(n);
    vector<vector<int>> dist(xf-xi,vector<int>(yf-yi));
    vector<vector<int>> vis(xf-xi,vector<int>(yf-yi));
    dist[xi][yi] = 0;
    vis[xi][yi] = 1;
    for(int i=0;i<n;i++){
            int a,b,c,d; cin >> a >> b >> c >> d;
            vx[i].first = a;
            vx[i].second = c;
            vy[i].first = b;
            vy[i].second = d;
    }
    while(!dq.empty()){
        auto usando = dq.front();
        int xu = usando.first;
        int yu = usando.second;
        dq.pop_front();
        for(auto [distx,disty] : moves){
            int xu2 = xu + distx;
            int yu2 = yu + disty;
            if(xu2 <= xf-xi && yu2 <=yf-yi){
            for(auto [u,w] : vx){
                for(auto [t,p] : vy){
                if(!vis[xu2][yu2] && (xu2 <= u && xu2 >= w) || (xu2 >= u && xu2 <= w) && (yu2 <= t && yu2 >= p) ||(yu2 >= t && yu2 <= p)){
                    dq.push_front(make_pair(xu2,yu2));
                    dist[xu2][yu2] = dist[xu][yu];
                }
                else{
                    dq.push_back(make_pair(xu2,yu2));
                    dist[xu2][yu2] = 1 + dist[xu][yu];
                }
                vis[xu2][yu2] = 1;
            }
            }
            }
        }
    }
    cout << dist[xf][yf] << endl;



}


int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        solve();
        return 0;
    }