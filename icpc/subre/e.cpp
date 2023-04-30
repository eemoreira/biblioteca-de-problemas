#include <bits/stdc++.h>

using namespace std;

const int mx = 1e4 + 5;

void solve(){
    int n; cin>>n;
    deque<int> q0,q1;
    int tempo = 0;
    for(int i = 0; i < n; i++){
        int p,d; cin >> p >> d;
        if(!d) q0.push_back(p);
        else q1.push_back(p);
    }
    int check,ok=0;
    if(!q0.empty()){
            int y = q1.front();
            q1.pop_front();
            int t=0;
            while(!q1.empty()){
                t+=y+10;
                if(y+10 < q1.front()){
                    cout << t << endl;
                    break;
                }
                else{
                    y = q1.front(); q1.pop_front();
                }
            }
            return;
       }
    if(!q1.empty()){
            int y = q0.front();
            q0.pop_front();
            int t=0;
            while(!q0.empty()){
                t+=y+10;
                if(y+10 < q0.front()){
                    cout << t << endl;
                    break;
                }
                else{
                    y = q0.front(); q0.pop_front();
                }
            }
       return;
       }
    while(!q0.empty() && !q1.empty()){
        int u;
        if(q0.empty()){
            u = q1.front(); q1.pop_front();
            check = 1;
        }
        else if(q0.front() > q1.front()){
            u = q1.front(); q1.pop_front();
            check = 1;
        }
        if(q1.empty()){
            u = q0.front(); q0.pop_front();
            check = 2;
        }
        else if(q1.front() > q0.front()){
            u = q0.front(); q0.pop_front();
            check = 2;
        }
        if(check == 2){
            while(!q0.empty()){
                if(q0.front() < u + 10){
                u = q0.front(); q0.pop_front();
                }
                else break;
                
            }
        }
        if(check == 1){
            while(!q0.empty()){
               if(q1.front() < u + 10){
                u = q1.front(); q1.pop_front();
                }
                else break;
            }
        }
        tempo += u+10;
        if(check == 2){
            if(q1.front() > u+10) {
                ok = 1;
                break;
            }
            q1.pop_front(); q1.push_front(tempo);
        }
        if(check == 1){
            if(q0.front() > u + 10){
                break;
                ok = 1;
            }
            q0.pop_front(); q0.push_front(tempo);
        }
    }
    if(ok){
        cout << tempo << endl;
        return;
    }   
    if(q1.empty()){
        int t = q0.front();
        q0.pop_front();
        while(!q0.empty()){
            if(t + 10 < q0.front() || q0.size() == 1){
                tempo+=t+10;
                break;
            }
            else q0.pop_front();
        }
    }
    if(q0.empty()){
        int t = q1.front();
        q1.pop_front();
        while(!q1.empty()){
            if(t + 10 < q1.front() || q1.size() == 1){
                tempo+=t+10;
                break;
            }
        }
    }
    cout << tempo + 10 << endl;
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

