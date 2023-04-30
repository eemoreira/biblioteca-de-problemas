#include <bits/stdc++.h>

void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){

    int L, C, casos;
    cin >> casos;

    for(int i=0; i<casos; i++){
        cin >> L >> C;
        vector<string> niveis(L);
        for(int k=0; k<L ;k++){
            string temp;
            cin >> temp;
            niveis[k] = temp;
        }
        vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0},{0,-1}};
        vector<vector<bool>> visited(L,vector<bool> (C));
        deque<pair<int, int>> dq;
        dq.push_front(make_pair(0,0)); //to access curent position later.
        visited[0][0] = true;
        vector<vector<int>> dist(L, vector<int>(C));
        dist[0][0] = 0;
        while(!dq.empty()){
                auto usando = dq.front();
                int x = usando.first;
                int y = usando.second; //store location
                dq.pop_front(); //pop first @ queue
                for(auto [distx, disty] : moves){
                    int x2 = x+distx;
                    int y2 = y+disty; // get all possible moves;
                    if(x2<L && x2>=0 && y2<C && y2>=0 && !visited[x2][y2]){
                        if(niveis[x2][y2] == niveis[x][y]){
                            dq.push_front(make_pair(x2,y2));
                            dist[x2][y2] = dist[x][y]; // same level = same distance and front of queue
                        }
                        else{
                            dq.push_back(make_pair(x2,y2));
                            dist[x2][y2] = dist[x][y] + 1; // not same level = dist + 1 and back of queue
                        }
                        visited[x2][y2] = true; // mark visited
                    }
                }
        }
            cout << dist[L-1][C-1] << endl;

    }
}



