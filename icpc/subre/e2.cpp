#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    deque<int> q0,q1;
    int tempo = 0;
    for(int i = 0; i < n; i++){
        int p,d; cin >> p >> d;
        if(!d) q0.push_back(p);
        else q1.push_back(p);
    }
    int check;
    if(q1.empty()){
        cout << q0.back() + 10 << endl;
        return;
    }
    if(q0.empty()){
        cout << q1.back() + 10 << endl;
        return;
    }
    while(!q1.empty() && !q0.empty()){
        int u;
        if(q1.front() > q0.front()){
            u = q0.front();
            check = 0;
            q0.pop_front();
        }
        else{
            u = q1.front();
            check = 1;
            q1.pop_front();
        }
        if(check == 1){
            while(!q1.empty()){
                if(q1.front() < u + 10){
                    u = q1.front();
                    q1.pop_front();
                }
                else{
                    tempo += u + 10;
                    break;
                }
                tempo += u + 10;
            }
            while(!q0.empty()){
                if(q0.front() < tempo){
                    q0.pop_front();
                }
                else{
                    tempo += 10 + q0.front() - tempo;
                    q0.pop_front();
                    break;
                }
                tempo += 10;
            }
        }
        if(check == 0){
            while(!q0.empty()){
                if(q0.front() < u + 10){
                    u = q0.front();
                    q0.pop_front();
                }
                else{
                    tempo += u + 10;
                    break;
                }
                tempo += u + 10;
            }
            while(!q1.empty()){
                if(q1.front() < tempo){
                    q1.pop_front();
                }
                else{
                    tempo += 10 + q1.front() - tempo;
                    q1.pop_front();
                    break;
                }
                tempo+=10;
            }
        }
    }
    if(q1.empty() && q0.empty()) cout << tempo << endl;
    else if(q0.empty()){
        while(!q1.empty()){
           if(q1.front() < tempo) tempo+=10;
           else tempo += q1.front() - tempo + 10;
           q1.pop_front();
        }
        cout << tempo << endl;
    }
    else if(q1.empty()){
        while(!q0.empty()){
           if(q0.front() < tempo) tempo+=10;
           else tempo += q0.front() - tempo + 10;
           q0.pop_front();
        }
        cout << tempo << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

