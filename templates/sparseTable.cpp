#define comp(a,b) min(a,b)

const int MAX;
int p2[MAX];
const int lg = 20;
const int neutral = 1e9;
vector<int> sparse[lg];
vector<int> a;
int n;

namespace sparseTable{
    void build(){ // dont forget to compute p2, change neutral/comp
        for(int i = 0; i < lg; i++){
            sparse[i] = vi(n, neutral);
        }
        for(int i = 0; i < n; i++){
            sparse[0][i] = a[i];
        }
        for(int i = 0; i < lg-1; i++){
            for(int j = 0; j + (1 << (i+1)) <= n;  j++){
                sparse[i+1][j] = comp(sparse[i][j], sparse[i][j + (1 << i)]);
            }
        }
    }
    int getvalue(int l, int r){
        int last = p2[r-l];
        return comp(sparse[last][l], sparse[last][r - (1 << last)]);
    }
}
