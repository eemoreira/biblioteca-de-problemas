#include <iostream>
#include <cmath>

using namespace std;
void solve();

int main(){
    solve();
    return 0;
}

void solve(){
    double dist, combst, angulo, arco, raio;

    cin >> raio >> dist >> combst;
    angulo = acos(1 - (dist*dist)/(2.0*raio*raio));

    arco = angulo*raio;

    if(combst >= (2.0*arco)){
        cout << "possivel" << endl;
    }
    else{
        cout << "impossivel" << endl;
    }
}
