#include <iostream>

using namespace std;

int main(){

    int i;
    float v[100];

    for(i=0;i<100;i++){
        cin >> v[i];
        if (v[i] < 10){
            cout << "A[" << i << "] = " <<  v[i] << endl;
        }
    }

}